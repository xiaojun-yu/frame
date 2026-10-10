#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QHash>
#include <QSet>
#include <QTimer>
#include "deb.h"
#include "database.h"
#include "databaseworker.h"
#include <QDialog>
#include <QDebug>

/*数据库相关*/
#include<QSqlDatabase>


//#include "../../Frame/deb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:  
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpServer *tcpServer = new QTcpServer();
    QTcpSocket *tcpSocket = new QTcpSocket();



 private slots:
    void on_pushButton_clicked();

    void ReData_Slot();

    void newConnection_Slot();
    void connected_Slot();
    void attemptClientReconnect();
    void scheduleClientReconnect();
    void sendDebugData(const QString &data);


    void on_sermode_clicked();
    void on_open_wifi_triggered();

    void on_led_triggered();

    void on_relay_triggered();

    void on_auto_hand_triggered();

    void on_debb_triggered();

    void on_exit_triggered();

    void on_charts1_big_clicked();

    void on_charts1_small_clicked();

    void on_charts1_rest_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_clear_yu_bt_clicked();

    void on_set_yu_bt_clicked();

    void on_set_light_bt_clicked();

    void on_charts1_big_2_clicked();

    void on_charts1_rest_2_clicked();

    void on_charts1_small_2_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_4_stateChanged(int arg1);

    void on_data_triggered();

signals:
    void saveSensorData(const QString &clientId,
                        double temp,
                        double humi,
                        double light,
                        double soil,
                        double mq2,
                        double rain);

private:
    Ui::MainWindow *ui;
    void creatChart();
    void creatChart2();

    //表刷新
    void DisplayChart1();
    void DisplayChart2();

    void BackDataParsing(const QString &strBuf, const QString &clientId);//数据解析
    void ToUpdata_Lab(QString Stemp,QString Shumi,QString Slight,QString Ssoil,QString Smq2,QString Srain);//更新至标签
    void handleReceivedCommand(QTcpSocket *socket, const QString &command);
    void attachSocket(QTcpSocket *socket, bool acceptedClient);
    void processSocketData(QTcpSocket *socket);
    void handleSocketDisconnected(QTcpSocket *socket);
    void closeServerClients();
    void sendNetworkData(const QByteArray &data);
    QHash<QTcpSocket *, QByteArray> receiveBuffers;
    QSet<QTcpSocket *> serverClients;
    QHash<QTcpSocket *, int> clientIds;
    QString assignedClientId;
    QTimer *reconnectTimer = nullptr;
    QTimer *heartbeatSendTimer = nullptr;
    QTimer *heartbeatTimeoutTimer = nullptr;

    //定时器1
     QTimer *timer;
    //调试窗口
     Deb *deb = new Deb;
     //数据库窗口
     database *dbui;
     QThread *databaseThread;
     DatabaseWorker *databaseWorker;
};
#endif // MAINWINDOW_H
