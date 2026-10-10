#include "mainwindow.h"
#include <QChartView>
#include <QLineSeries>          //线条类
#include <QtMath>

#include <QTimer>               //时间类
#include <QDateTime>
#include <QDateTimeAxis>        //时间坐标轴类
#include <QValueAxis>           //普通坐标轴类
#include <QMessageBox>
#include <QMetaObject>
#include <string>
#include <QDebug>

#include "ui_mainwindow.h"


bool MS = true;//t 主机
bool flag_Sw=false;//
bool run_mode=true;//自动

//继电器
bool relaySw=false;

//温湿度变量
float temp_data;
float humi_data;
float light_data;

float soil_data;
float mq2_data;
float rain_data;

/*阈值*/
QString EnsoilHumi;
QString Enrain;
QString Entemp;
QString Enlight;

//光强
short light_pwm;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 调试窗口的数据发送到当前主窗口的 TCP 连接，不再临时创建另一个 MainWindow。
    connect(deb, &Deb::sendData,
            this, &MainWindow::sendDebugData);
    // 网络回调只绑定一次；实际连接建立后继续使用同一组处理函数。
    attachSocket(tcpSocket, false);
    connect(tcpSocket, &QTcpSocket::connected,
            this, &MainWindow::connected_Slot);
    reconnectTimer = new QTimer(this);
    reconnectTimer->setSingleShot(true);
    connect(reconnectTimer, &QTimer::timeout,
            this, &MainWindow::attemptClientReconnect);
    connect(tcpSocket, &QTcpSocket::errorOccurred, this,
            [this](QAbstractSocket::SocketError) {
                // 初次连接失败时也会触发错误信号；若仍处于客户机联网状态，安排重试。
                scheduleClientReconnect();
            });

    heartbeatSendTimer = new QTimer(this);
    heartbeatSendTimer->setInterval(3000);
    connect(heartbeatSendTimer, &QTimer::timeout, this, [this]() {
        if (!MS && flag_Sw
            && tcpSocket->state() == QAbstractSocket::ConnectedState) {
            if (tcpSocket->write("PING\n") == -1) {
                qWarning() << "发送心跳失败：" << tcpSocket->errorString();
                tcpSocket->abort();
            }else {
                qDebug() << "客户机发送 PING";
            }
        }
    });

    heartbeatTimeoutTimer = new QTimer(this);
    heartbeatTimeoutTimer->setSingleShot(true);
    connect(heartbeatTimeoutTimer, &QTimer::timeout, this, [this]() {
        if (!MS && flag_Sw
            && tcpSocket->state() == QAbstractSocket::ConnectedState) {
            qWarning() << "10 秒内未收到主机心跳回应，断开并启动自动重连";
            tcpSocket->abort();
        }
    });

    //创建表一
    creatChart();

    creatChart2();
    //创建定时器 表格更新
    timer=new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(ReData_Slot()));

    //网络设置

    //默认使用主机模式，等待新的连接
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection_Slot()));


    //工具栏大小设置
     QSize si;
     si.setWidth(40);
     si.setHeight(40);
     ui->toolBar->setIconSize(si);


    ui->horizontalSlider->setRange(0,100);
    setFixedSize(950,545);

    ui->ip_edi->setText("192.168.1.5");
    ui->port_edi->setText("8080");
    //蓄水
    ui->progressBar->setValue(0);
    ui->spinBox->setValue(5);


    /*数据库内容*/
    //初始化数据库
    dbui = new database;

    // 数据库写入使用独立线程和独立的 Qt SQL 连接。
    databaseThread = new QThread(this);
    databaseWorker = new DatabaseWorker;
    databaseWorker->moveToThread(databaseThread);

    connect(databaseThread, &QThread::started,
            databaseWorker, &DatabaseWorker::initialize,
            Qt::DirectConnection);
    connect(this, &MainWindow::saveSensorData,
            databaseWorker, &DatabaseWorker::insertSensorData);
    connect(databaseWorker, &DatabaseWorker::databaseError,
            this, [](const QString &message) {
                qWarning() << "异步数据库错误：" << message;
            });
    connect(databaseWorker, &DatabaseWorker::recordInserted,
            this, []() {
                qDebug() << "传感器记录已由数据库线程写入";
            });
    connect(databaseWorker, &DatabaseWorker::recordInserted,
            this, [this]() {
                if (dbui->isVisible()) {
                    dbui->SelectAllPushTableData();
                }
            });
    connect(databaseThread, &QThread::finished,
            databaseWorker, &QObject::deleteLater);
    databaseThread->start();

    setWindowTitle("--物联网智能终端--  测试版  V5.1 原作者: 拾贰, 修改: 程序员summer");
//    ui->tempicon->setToolTip("湿度");
//    ui->tempicon->setStyleSheet("QLabel { qproperty-toolTip: '这是一个提示信息。';}");

}

/*网络部分*/
//检测是否有新连接进来
void MainWindow::newConnection_Slot(){
    // 一次 newConnection 通知期间可能已有多个连接排队，逐个接收。
    while (tcpServer->hasPendingConnections()) {
        QTcpSocket *socket = tcpServer->nextPendingConnection();
        if (!socket)
            continue;

        QSet<int> usedClientIds;
        for (int activeId : clientIds)
            usedClientIds.insert(activeId);

        int clientId = 1;
        while (clientId <= 10000 && usedClientIds.contains(clientId))
            ++clientId;

        if (clientId > 10000) {
            qWarning() << "客户端编号 1-10000 已用完，拒绝新连接";
            socket->disconnectFromHost();
            socket->deleteLater();
            continue;
        }

        serverClients.insert(socket);
        clientIds.insert(socket, clientId);
        attachSocket(socket, true);
        socket->write(QStringLiteral("client_id:%1\n").arg(clientId).toUtf8());
        ui->connect_l->setStyleSheet("border-image: url(:/connect.png)");
        qDebug() << "new client:" << socket->peerAddress().toString()
                 << ":" << socket->peerPort()
                 << "client_id:" << clientId
                 << "active clients:" << serverClients.size();
    }
}

//客户机连接
void MainWindow::connected_Slot(){
    if (reconnectTimer)
        reconnectTimer->stop();
    assignedClientId.clear(); // 每次重新连接后等待服务器重新分配会话 ID。
    if (!MS && flag_Sw) {
        heartbeatTimeoutTimer->start(10000);
        heartbeatSendTimer->start();
    }
    qDebug() << "connect to " << ui->ip_edi->text() << ":" << ui->port_edi->text().toUInt();
    ui->connect_l->setStyleSheet("border-image: url(:/connect.png)");
}

void MainWindow::scheduleClientReconnect()
{
    if (!flag_Sw || MS || !reconnectTimer
        || tcpSocket->state() != QAbstractSocket::UnconnectedState
        || reconnectTimer->isActive()) {
        return;
    }

    qWarning() << "客户机连接断开，将在 5 秒后重试连接";
    reconnectTimer->start(5000);
}

void MainWindow::attemptClientReconnect()
{
    if (!flag_Sw || MS || tcpSocket->state() != QAbstractSocket::UnconnectedState)
        return;

    const QString host = ui->ip_edi->text().trimmed();
    const quint16 port = static_cast<quint16>(ui->port_edi->text().toUInt());
    qDebug() << "客户机正在重连：" << host << ":" << port;
    tcpSocket->connectToHost(host, port);
}

void MainWindow::attachSocket(QTcpSocket *socket, bool acceptedClient)
{
    if (!socket || receiveBuffers.contains(socket))
        return;

    receiveBuffers.insert(socket, QByteArray());
    if (acceptedClient)
        serverClients.insert(socket);

    connect(socket, &QTcpSocket::readyRead, this,
            [this, socket]() { processSocketData(socket); });
    connect(socket, &QTcpSocket::disconnected, this,
            [this, socket]() { handleSocketDisconnected(socket); });
}

void MainWindow::processSocketData(QTcpSocket *socket)
{
    auto it = receiveBuffers.find(socket);
    if (it == receiveBuffers.end())
        return;

    it.value().append(socket->readAll());
    constexpr qsizetype maxBufferedBytes = 64 * 1024;
    if (it.value().size() > maxBufferedBytes
        && !it.value().contains('\n')) {
        qWarning() << "TCP frame exceeded buffer limit; disconnecting"
                   << socket->peerAddress().toString();
        socket->disconnectFromHost();
        return;
    }

    // Each socket has its own byte buffer, so partial frames from clients cannot mix.
    int newline = -1;
    while ((newline = it.value().indexOf('\n')) >= 0) {
        const QByteArray frame = it.value().left(newline).trimmed();
        it.value().remove(0, newline + 1);
        if (frame.isEmpty())
            continue;

        const QString command = QString::fromUtf8(frame);
        if (command != QStringLiteral("PING")
            && command != QStringLiteral("PONG")) {
            qDebug() << "readyRead_Slot:" << command;
            deb->DisplayData(command);
        }
        handleReceivedCommand(socket, command);
    }

    if (it.value().size() > maxBufferedBytes) {
        qWarning() << "TCP receive buffer exceeded limit; disconnecting"
                   << socket->peerAddress().toString();
        socket->disconnectFromHost();
    }
}

void MainWindow::handleSocketDisconnected(QTcpSocket *socket)
{
    if (socket == tcpSocket) {
        heartbeatSendTimer->stop();
        heartbeatTimeoutTimer->stop();
    }

    const bool wasServerClient = serverClients.remove(socket) > 0;
    if (wasServerClient)
        receiveBuffers.remove(socket);
    else
        receiveBuffers[socket].clear(); // retain client-mode socket for reconnection

    const int clientId = clientIds.take(socket);
    qDebug() << "socket disconnected; client_id:" << clientId
             << "active server clients:" << serverClients.size();
    if (wasServerClient)
        socket->deleteLater();

    if ((MS && serverClients.isEmpty()) || (!MS && socket == tcpSocket))
        ui->connect_l->setStyleSheet("border-image: url(:/discon.png)");

    if (!wasServerClient && socket == tcpSocket)
        scheduleClientReconnect();
}

void MainWindow::closeServerClients()
{
    const auto clients = serverClients.values();
    serverClients.clear();
    for (QTcpSocket *socket : clients) {
        receiveBuffers.remove(socket);
        clientIds.remove(socket);
        socket->disconnect(this);
        socket->disconnectFromHost();
        socket->deleteLater();
    }
}

void MainWindow::sendNetworkData(const QByteArray &data)
{
    if (MS) {
        int sentCount = 0;
        const auto clients = serverClients.values();
        for (QTcpSocket *socket : clients) {
            if (socket && socket->state() == QAbstractSocket::ConnectedState
                && socket->write(data) != -1) {
                ++sentCount;
            }
        }
        if (sentCount == 0)
            qWarning() << "No connected client; message not sent:" << data.trimmed();
        else
            qDebug() << "Sent to" << sentCount << "client(s):" << data.trimmed();
        return;
    }

    if (tcpSocket->state() != QAbstractSocket::ConnectedState) {
        qWarning() << "TCP is not connected; message not sent:" << data.trimmed();
        return;
    }
    if (tcpSocket->write(data) == -1)
        qWarning() << "TCP send failed:" << tcpSocket->errorString();
}

//文本显示
void MainWindow::ToUpdata_Lab(QString Stemp,QString Shumi,QString Slight,QString Ssoil,QString Smq2,QString Srain){
    ui->temp_la->setText(Stemp+"%");
    ui->humi_la->setText(Shumi+"%");
    ui->light_la->setText(Slight+"%");

    ui->soil_la->setText(Ssoil+"%");
    ui->mq2_la->setText(Smq2+"%");
    ui->rain_la->setText(Srain+"%");

}

void MainWindow::handleReceivedCommand(QTcpSocket *socket, const QString &command)
{
    QString cmd = command.trimmed();

    // 忽略空消息
    if (cmd.isEmpty()) {
        return;
    }

    // 心跳是连接保活消息，不进入传感器解析或数据库写入。
    if (cmd == QStringLiteral("PING")) {
        if (socket->state() == QAbstractSocket::ConnectedState
            && socket->write("PONG\n") == -1) {
            qWarning() << "回复心跳失败：" << socket->errorString();
        }else
            qDebug() << "主机发送 PONG";
        return;
    }

    if (cmd == QStringLiteral("PONG")) {
        if (!MS && socket == tcpSocket && flag_Sw){
            qDebug() << "客户机收到 PONG";
            heartbeatTimeoutTimer->start(10000);
        }

        return;
    }

    qDebug() << "收到命令：" << cmd;

    if (cmd.startsWith("client_id:")) {
        if (!MS && socket == tcpSocket) {
            assignedClientId = cmd.mid(QStringLiteral("client_id:").size()).trimmed();
            qDebug() << "服务器分配的 client_id:" << assignedClientId;
        }
        return;
    }

    /*
     * 开启继电器。
     * 命令格式：relay_on:5
     * 冒号后面是主机设定的持续时间。
     */
    if (cmd.startsWith("relay_on:")) {

        // 控制命令只应该由客户机执行
        if (MS) {
            qDebug() << "主机忽略 relay_on 命令";
            return;
        }

        bool ok = false;

        int duration =
            cmd.section(':', 1, 1).toInt(&ok);

        if (!ok || duration <= 0) {
            qDebug()
            << "继电器持续时间无效："
            << cmd;
            return;
        }

        relaySw = true;

        // 使用主机发来的持续时间
        ui->spinBox->setValue(duration);

        // 从 0% 开始蓄水
        ui->progressBar->setValue(0);

        ui->relay->setIcon(
            QIcon(":/relay_on.png"));

        qDebug()
            << "客户机：继电器已开启，持续"
            << duration
            << "秒";

        return;
    }

    /*
     * 兼容旧版不带时间的 relay_on。
     * 后续可以删除这段兼容逻辑。
     */
    if (cmd == "relay_on") {

        if (MS) {
            return;
        }

        relaySw = true;

        ui->progressBar->setValue(0);

        ui->relay->setIcon(
            QIcon(":/relay_on.png"));

        qDebug()
            << "客户机：继电器已开启，使用本地时间"
            << ui->spinBox->value()
            << "秒";

        return;
    }

    /*
     * 关闭继电器。
     * 当前项目将 relay_off 视为定时蓄水完成，
     * 因此进度保持在 100%。
     */
    if (cmd == "relay_off") {

        if (MS) {
            qDebug()
            << "主机忽略收到的 relay_off";
            return;
        }

        relaySw = false;

        ui->relay->setIcon(
            QIcon(":/relay_off.png"));

        ui->progressBar->setValue(100);

        qDebug()
            << "客户机：继电器已关闭，蓄水完成";

        return;
    }

    /*
     * 解析客户机上传的传感器数据。
     */
    if (cmd.startsWith("Params{")) {

        // 传感器数据由主机处理
        if (MS) {
            const auto clientIdIt = clientIds.constFind(socket);
            const QString clientId = clientIdIt == clientIds.cend()
                ? QStringLiteral("unknown")
                : QString::number(clientIdIt.value());
            BackDataParsing(cmd, clientId);
        }

        return;
    }
    if (cmd.startsWith("Pwm:")) {

        if (MS) {
            return;
        }

        bool ok = false;
        int pwm = cmd.section(':', 1, 1).toInt(&ok);

        if (!ok || pwm < 0 || pwm > 100) {
            qDebug() << "无效的 PWM 数值：" << cmd;
            return;
        }

        ui->horizontalSlider->setValue(pwm);
        ui->setlightNumla->setNum(pwm);

        qDebug() << "客户机：光强设置为"
                 << pwm << "%";

        // 连接真实硬件时，在这里设置实际 PWM。
        return;
    }

    qDebug() << "未知命令：" << cmd;
}

//数据解析
void MainWindow::BackDataParsing(const QString &strBuf, const QString &clientId){

    //查找是否为参数;  -1表示没有该子串
   if(strBuf.startsWith("Params")){

        //表一数据
        QString str = strBuf.mid(strBuf.indexOf("temp:")+((QString)"temp:").length(),strBuf.indexOf("humi:")-strBuf.indexOf("temp:")-((QString)"temp:").length()-1);
        QString st2 = strBuf.mid(strBuf.indexOf("humi:")+((QString)"humi:").length(),strBuf.indexOf("light:")-strBuf.indexOf("humi:")-((QString)"humi:").length()-1);
        QString st3 = strBuf.mid(strBuf.indexOf("light:")+((QString)"light:").length(),strBuf.indexOf("soil:")-strBuf.indexOf("light:")-((QString)"light:").length()-1);


        //表二数据
        QString st4 = strBuf.mid(strBuf.indexOf("soil:")+((QString)"soil:").length(),strBuf.indexOf("mq2:")-strBuf.indexOf("soil:")-((QString)"soil:").length()-1);
        QString st5 = strBuf.mid(strBuf.indexOf("mq2:")+((QString)"mq2:").length(),strBuf.indexOf("rain:")-strBuf.indexOf("mq2:")-((QString)"mq2:").length()-1);
        QString st6 = strBuf.mid(strBuf.indexOf("rain:")+((QString)"rain:").length(),strBuf.indexOf("}")-strBuf.indexOf("rain:")-((QString)"rain:").length()-1);


        //更新至表格
         temp_data = str.toFloat();
         humi_data = st2.toFloat();
         light_data = st3.toFloat();

         soil_data = st4.toFloat();
         mq2_data = st5.toFloat();
         rain_data = st6.toFloat();

       //送入标签
       ToUpdata_Lab(str,st2,st3,st4,st5,st6);

       // 通过队列信号异步写入数据库，避免阻塞界面线程。
        emit saveSensorData(clientId, temp_data, humi_data, light_data,
                            soil_data, mq2_data, rain_data);

   }
}

MainWindow::~MainWindow()
{
    tcpServer->close();
    closeServerClients();
    tcpSocket->close();

    if (databaseThread && databaseThread->isRunning()) {
        QMetaObject::invokeMethod(databaseWorker, "shutdown",
                                  Qt::BlockingQueuedConnection);
        databaseThread->quit();
        databaseThread->wait();
    }

    delete ui;
}

//发送标志位
void MainWindow::sendDebugData(const QString &data)
{
    const QByteArray frame = (data + QLatin1Char('\n')).toUtf8();
    sendNetworkData(frame);
}

//创建chart
void MainWindow::creatChart()
{
    QChart *qchart = new QChart();
    //把chart放到容器里
    ui->graphicsView->setChart(qchart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); //设置抗锯齿

    //创建两条线
    QLineSeries *series0 = new QLineSeries;
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;

    //设置名字
    series0->setName("温度");
    series1->setName("湿度");
    series2->setName("光强");

    //把线条放到chart里
    qchart->addSeries(series0);
    qchart->addSeries(series1);
    qchart->addSeries(series2);

    //创建x 坐标
    QDateTimeAxis *axisX = new QDateTimeAxis;

    //格式
    axisX->setFormat("hh:mm:ss");
    //设置竖条数量
    axisX->setTickCount(5);

    //设置坐标名称
    axisX->setTitleText("time(sec)");

    qchart->setAxisX(axisX,series0);
    qchart->setAxisX(axisX,series1);
    qchart->setAxisX(axisX,series2);

    //创建y坐标
    QValueAxis  *axisY = new QValueAxis;
    axisY->setRange(0,100);
    axisY->setTickCount(5);

    qchart->setAxisY(axisY,series0);
    qchart->setAxisY(axisY,series1);
    qchart->setAxisY(axisY,series2);

    qchart->setDropShadowEnabled(true);

    //初始化坐标
         //设置最大值坐标值 系统时间当前时间
    qchart->axisX()->setMin(QDateTime::currentDateTime().addSecs(0));
         //设置最大值坐标值 系统时间后5*30秒
    qchart->axisX()->setMax(QDateTime::currentDateTime().addSecs(5*30));

}
void MainWindow::creatChart2(){
    QChart *qchart = new QChart();
    //qchart->setTitle("数据图表");
    //把chart放到容器里
    ui->graphicsView_2->setChart(qchart);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing); //设置抗锯齿`

    //创建两条线
    QLineSeries *series0 = new QLineSeries;
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;

    //设置名字
    series0->setName("土壤湿度");
    series1->setName("有害气体");
    series2->setName("雨滴");

    //把线条放到chart里
    qchart->addSeries(series0);
    qchart->addSeries(series1);
    qchart->addSeries(series2);

    qchart->setDropShadowEnabled(true);


    //创建x 坐标
    //QValueAxis  *axisX = new QValueAxis;
    QDateTimeAxis *axisX = new QDateTimeAxis;

    //格式
    axisX->setFormat("hh:mm:ss");
    //设置竖条数量
    axisX->setTickCount(5);
    //设置坐标轴上次刻度线的数量。
   // axisX->setMinorTickCount(2);

    //设置坐标名称
    axisX->setTitleText("time(sec)");

    qchart->setAxisX(axisX,series0);
    qchart->setAxisX(axisX,series1);
    qchart->setAxisX(axisX,series2);

    //创建y坐标
    QValueAxis  *axisY = new QValueAxis;
    axisY->setRange(0,100);
    qchart->setAxisY(axisY,series0);
    qchart->setAxisY(axisY,series1);
    qchart->setAxisY(axisY,series2);

}


//表刷新
void MainWindow::DisplayChart1(){

    //获取当前时间
    QDateTime currentTime = QDateTime::currentDateTime();

    //获取初始化的qchart
    QChart *qchart =(QChart *)ui->graphicsView->chart();
    //获取初始化的series;
    QLineSeries *series0 = (QLineSeries *)ui->graphicsView->chart()->series().at(0);
    QLineSeries *series1 = (QLineSeries *)ui->graphicsView->chart()->series().at(1);
    QLineSeries *series2 = (QLineSeries *)ui->graphicsView->chart()->series().at(2);

    series0->append(currentTime.toMSecsSinceEpoch(),temp_data);
    series1->append(currentTime.toMSecsSinceEpoch(),humi_data);
    series2->append(currentTime.toMSecsSinceEpoch(),light_data);

    qchart->axisX()->setMin(QDateTime::currentDateTime().addSecs(-5*30));
    qchart->axisX()->setMax(QDateTime::currentDateTime().addSecs(5*30));
}
void MainWindow::DisplayChart2(){
    //获取当前时间
    QDateTime currentTime = QDateTime::currentDateTime();

    //获取初始化的qchart
    QChart *qchart =(QChart *)ui->graphicsView_2->chart();
    //获取初始化的series;
    QLineSeries *series0 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(0);
    QLineSeries *series1 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(1);
    QLineSeries *series2 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(2);

    series0->append(currentTime.toMSecsSinceEpoch(),soil_data);
    series1->append(currentTime.toMSecsSinceEpoch(),mq2_data);
    series2->append(currentTime.toMSecsSinceEpoch(),rain_data);

    qchart->axisX()->setMin(QDateTime::currentDateTime().addSecs(-5*30));
    qchart->axisX()->setMax(QDateTime::currentDateTime().addSecs(5*30));
}

//时间刷新
void MainWindow::ReData_Slot(){
    static int timer=0;

    DisplayChart1();
    DisplayChart2();


    //temp_data

    //当前时间
    ui->time_l->setText(QTime::currentTime().toString("hh:mm:ss"));

    //继电器控制
    if(relaySw){
        timer++;
        // boVal 设定值  timer 当前值
        int boVal = ui->spinBox->value();

        ui->progressBar->setValue((timer*100)/boVal);

            //超时后自动关闭
        if(timer>=boVal){
            timer=0;
            relaySw=false;
            ui->relay->setIcon(QIcon(":/relay_off.png"));
            //tcpSocket->write("relay_off");
            ui->progressBar->setValue(100);
            if (MS)
                sendNetworkData("relay_off\n");
        }
      }
    else
    {
      //  ui->progressBar->setValue(0);
        timer=0;
    }
}

//主副机切换
void MainWindow::on_sermode_clicked()
{
    if(!flag_Sw)
    {
       //全关闭
       tcpServer->close();
       closeServerClients();
       tcpSocket->close();
       //客户机
       if(MS){
           MS=false;
           ui->sermode_l->setText("客户机模式");
           ui->sermode->setStyleSheet("border-image: url(:/client.png);");
       }

       else//主机
       {
           MS=true;
           ui->sermode_l->setText("主机模式");
           ui->sermode->setStyleSheet("border-image: url(:/server.png);");
       }
    }
    else
       QMessageBox::critical(this,"提示","请先关闭网络，再切换模式类型");
}



//总网络开关
void MainWindow::on_open_wifi_triggered()
{
   // ui->open_wifi->setIcon(QIcon(":open.png"));

    flag_Sw=!flag_Sw;

    if(flag_Sw){
        //打开
        //ui->switch_bt->setStyleSheet("border-image: url(:/open.png);");
        ui->wifi_l->setStyleSheet("border-image: url(:/wifi_on.png);");
        ui->open_wifi->setIcon(QIcon(":open.png"));

        //选择主机
        if(MS)
        {
            tcpServer->listen(QHostAddress::Any,ui->port_edi->text().toUInt()); //监听端口
            qDebug() << "这是主机";
        }
        else//客户机
        {
            if (reconnectTimer)
                reconnectTimer->stop();
            tcpSocket->connectToHost(ui->ip_edi->text(),ui->port_edi->text().toUInt());
            qDebug() << "这是客户机";
        }
    }else{
        //关闭
        //ui->switch_bt->setStyleSheet("border-image: url(:/close.png);");
        ui->wifi_l->setStyleSheet("border-image: url(:/wifi_off.png);");
        ui->open_wifi->setIcon(QIcon(":close.png"));

        if (reconnectTimer)
            reconnectTimer->stop();
        heartbeatSendTimer->stop();
        heartbeatTimeoutTimer->stop();

        tcpServer->close();
        closeServerClients();
        tcpSocket->close();
    }
}

//led 开关
void MainWindow::on_led_triggered()
{
    static bool ledSw=false;
    ledSw=!ledSw;

    if(ledSw){
        ui->led->setIcon(QIcon(":/led_on.png"));
         sendNetworkData("led_on\n");
    }
    else{
         ui->led->setIcon(QIcon(":/led_off.png"));
          sendNetworkData("led_off\n");
    }

}
//继电器开关
void MainWindow::on_relay_triggered()
{

    // relaySw=!relaySw;

    // if(relaySw){
    //     ui->relay->setIcon(QIcon(":/relay_on.png"));
    //      tcpSocket->write("relay_on");
    // }
    // else{
    //      ui->relay->setIcon(QIcon(":/relay_off.png"));
    //      tcpSocket->write("relay_off");
    // }
    if (!MS) {
        QMessageBox::information(
            this,
            "提示",
            "请在主机模式下控制继电器");
        return;
    }

    // 必须已经建立 TCP 连接
    if (serverClients.isEmpty()) {

        QMessageBox::warning(
            this,
            "提示",
            "客户机尚未连接");
        return;
    }

    relaySw = !relaySw;

    if (relaySw) {
        int duration =
            qMax(1, ui->spinBox->value());

        ui->relay->setIcon(
            QIcon(":/relay_on.png"));

        QString command =
            QString("relay_on:%1\n")
                .arg(duration);

        sendNetworkData(command.toUtf8());

        qDebug() << "主机发送：" << command;
    } else {
        ui->relay->setIcon(
            QIcon(":/relay_off.png"));

        sendNetworkData("relay_off\n");

        qDebug() << "主机发送：relay_off";
    }

}
//run mode
void MainWindow::on_auto_hand_triggered()
{
    run_mode=!run_mode;

    if(run_mode){

        ui->auto_hand->setIcon(QIcon(":/auto.png"));
       sendNetworkData("auto_mode\n");
    }
    else{
        //手动
         ui->auto_hand->setIcon(QIcon(":/hand.png"));
         sendNetworkData("hand_mode\n");
    }
}
//调出调试窗口
void MainWindow::on_debb_triggered()
{
    deb->show();
}
//退出主窗口
void MainWindow::on_exit_triggered()
{
    this->close();
}

/*表格控件*/
void MainWindow::on_charts1_big_clicked()
{
    ui->graphicsView->chart()->zoom(1.2);
}

void MainWindow::on_charts1_small_clicked()
{
    ui->graphicsView->chart()->zoom(0.8);
}

void MainWindow::on_charts1_rest_clicked()
{
    ui->graphicsView->chart()->zoomReset();
}

//清空表一数据
void MainWindow::on_pushButton_clicked()
{
    QLineSeries *series0 = (QLineSeries *)ui->graphicsView->chart()->series().at(0);
    QLineSeries *series1 = (QLineSeries *)ui->graphicsView->chart()->series().at(1);
    QLineSeries *series2 = (QLineSeries *)ui->graphicsView->chart()->series().at(2);

    series0->clear();
    series1->clear();
    series2->clear();
}


void MainWindow::on_charts1_big_2_clicked()
{
    ui->graphicsView_2->chart()->zoom(1.2);
}

void MainWindow::on_charts1_rest_2_clicked()
{
    ui->graphicsView_2->chart()->zoomReset();
}

void MainWindow::on_charts1_small_2_clicked()
{
    ui->graphicsView_2->chart()->zoom(0.8);
}

void MainWindow::on_pushButton_2_clicked()
{
    QLineSeries *series0 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(0);
    QLineSeries *series1 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(1);
    QLineSeries *series2 = (QLineSeries *)ui->graphicsView_2->chart()->series().at(2);

    series0->clear();
    series1->clear();
    series2->clear();
}



/*
short soilHumi_threshold;
short rain_threshold;
short temp_threshold;

*/

//复选框  2选中 0未选中
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<arg1;
    if(arg1==2)
        EnsoilHumi="enable";
    else
        EnsoilHumi="disable";
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    qDebug()<<arg1;

    if(arg1==2)
         Enrain="enable";
    else
         Enrain="disable";
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
     qDebug()<<arg1;

     if(arg1==2)
          Entemp="enable";
     else
          Entemp="disable";
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{

    if(arg1==2)
         Enlight="enable";
    else
         Enlight="disable";
}

//清空内容
void MainWindow::on_clear_yu_bt_clicked()
{
     ui->checkBox->setChecked(false);
     ui->checkBox_2->setChecked(false);
     ui->checkBox_3->setChecked(false);
     ui->checkBox_4->setChecked(false);

     ui->soil_yu_la->clear();
     ui->temp_yu_la->clear();
     ui->rain_yu_la->clear();
     ui->light_yu_la->clear();

}
void MainWindow::on_set_yu_bt_clicked()
{
    QString sendThrshold;

    sendThrshold = EnsoilHumi + " " + "soil:"+ ui->soil_yu_la->text()+";"+
                   Enrain     + " " + "rain:"+ ui->rain_yu_la->text()+";"+
                   Entemp     + " " + "temp:"+ ui->temp_yu_la->text()+";"+
                   Enlight    + " " + "light:"+ui->light_yu_la->text();

    sendNetworkData((sendThrshold + QLatin1Char('\n')).toLocal8Bit());

}

//滑动改变
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
     ui->setlightNumla->setNum(value);
     light_pwm = value;
}

//光强控制
void MainWindow::on_set_light_bt_clicked()
{
   sendNetworkData(("Pwm:" + QString::number(light_pwm) + QLatin1Char('\n')).toLocal8Bit());
}


/*数据库操作*/
void MainWindow::on_data_triggered()
{
    dbui->SelectAllPushTableData();
    dbui->show();
}
