#ifndef DATABASEWORKER_H
#define DATABASEWORKER_H

#include <QObject>
#include <QString>

class DatabaseWorker : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseWorker(QObject *parent = nullptr);

public slots:
    void initialize();
    void insertSensorData(const QString &clientId,
                          double temp,
                          double humi,
                          double light,
                          double soil,
                          double mq2,
                          double rain);
    void shutdown();

signals:
    void databaseError(const QString &message);
    void recordInserted();

private:
    QString m_connectionName;
    bool m_ready = false;
};

#endif // DATABASEWORKER_H
