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

    m_ready = true;
}

void DatabaseWorker::insertSensorData(double temp,
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
        " (curren_time, temp, humi, light, soil, mq2, rain)"
        " VALUES (?, ?, ?, ?, ?, ?, ?)");
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
