#include "databaseworker.h"

#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

DatabaseWorker::DatabaseWorker(QObject *parent)
    : QObject(parent),
      m_connectionName(QStringLiteral("frame_async_writer"))
{
}

void DatabaseWorker::initialize()
{
    if (QSqlDatabase::contains(m_connectionName)) {
        QSqlDatabase::removeDatabase(m_connectionName);
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", m_connectionName);
    db.setDatabaseName(
        "DRIVER={MySQL ODBC 8.0 Unicode Driver};"
        "SERVER=127.0.0.1;"
        "PORT=3306;"
        "DATABASE=qtsql;"
        "OPTION=3;");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open()) {
        emit databaseError(db.lastError().text());
        return;
    }

    // Upgrade older local databases without replacing their existing rows.
    QSqlQuery columnCheck(db);
    columnCheck.prepare(
        "SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS "
        "WHERE TABLE_SCHEMA = DATABASE() "
        "AND TABLE_NAME = 'qtdata' AND COLUMN_NAME = 'client_id'");
    if (!columnCheck.exec() || !columnCheck.next()) {
        emit databaseError(QStringLiteral("检查 client_id 字段失败：")
                           + columnCheck.lastError().text());
        return;
    }
    const bool hasClientIdColumn = columnCheck.value(0).toInt() > 0;
    columnCheck.finish();
    if (!hasClientIdColumn) {
        QSqlQuery addColumn(db);
        if (!addColumn.exec(
                "ALTER TABLE qtdata ADD COLUMN client_id "
                "VARCHAR(36) NOT NULL DEFAULT 'legacy'")) {
            emit databaseError(QStringLiteral("添加 client_id 字段失败：")
                               + addColumn.lastError().text());
            return;
        }
    }

    m_ready = true;
}

void DatabaseWorker::insertSensorData(const QString &clientId,
                                      double temp,
                                      double humi,
                                      double light,
                                      double soil,
                                      double mq2,
                                      double rain)
{
    if (!m_ready) {
        emit databaseError(QStringLiteral("数据库写入线程尚未连接数据库。"));
        return;
    }

    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO qtdata"
        " (client_id, curren_time, temp, humi, light, soil, mq2, rain)"
        " VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(clientId);
    query.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    query.addBindValue(temp);
    query.addBindValue(humi);
    query.addBindValue(light);
    query.addBindValue(soil);
    query.addBindValue(mq2);
    query.addBindValue(rain);

    if (!query.exec()) {
        emit databaseError(query.lastError().text());
        return;
    }

    emit recordInserted();
}

void DatabaseWorker::shutdown()
{
    m_ready = false;

    if (!QSqlDatabase::contains(m_connectionName)) {
        return;
    }

    {
        QSqlDatabase db = QSqlDatabase::database(m_connectionName, false);
        if (db.isValid()) {
            db.close();
        }
    }

    QSqlDatabase::removeDatabase(m_connectionName);
}
