#include "database.h"
#include "ui_database.h"

#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>

database::database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::contains()
            ? QSqlDatabase::database()
            : QSqlDatabase::addDatabase("QODBC");

    // QODBC 的 setDatabaseName 需要 DSN 或完整连接字符串。
    // 这里使用无 DSN 连接，直接指定已安装的 64 位 MySQL ODBC 驱动。
    db.setDatabaseName(
        "DRIVER={MySQL ODBC 8.0 Unicode Driver};"
        "SERVER=127.0.0.1;"
        "PORT=3306;"
        "DATABASE=qtsql;"
        "OPTION=3;"
    );
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if (ok){
         qDebug()<<"success";
    }
    else {
        QMessageBox::information(this, "警告！", "DataBase Open Failed，Check whether there is a database or whether the parameters are correct!!!");
        qDebug()<<"error open database because"<<db.lastError().text();
        ui->label->setText(db.lastError().text());
    }
      //查询所有并放入表中
     SelectAllPushTableData();

     //初始化表格 格式
     ui->tableView->setColumnWidth(0,80);
     ui->tableView->setColumnWidth(1,150);
     ui->tableView->setColumnWidth(2,70);
     ui->tableView->setColumnWidth(3,70);
     ui->tableView->setColumnWidth(4,70);
     ui->tableView->setColumnWidth(5,70);
     ui->tableView->setColumnWidth(6,70);
     ui->tableView->setColumnWidth(7,70);

     /*初始化下拉框*/
     ui->comboBox->addItem("temp");
     ui->comboBox->addItem("humi");
     ui->comboBox->addItem("light");

     ui->comboBox->addItem("soil");
     ui->comboBox->addItem("mq2");
     ui->comboBox->addItem("rain");

     /*设置日期查询的初始化*/
     ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime().addSecs(0));
     ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(0));

     setFixedSize(750,650);

     setWindowTitle("——数据库管理平台——");
//     double data[6] = {1, 2.2, 3, 4,5, 6}; //只是用来测试数据用的
//     insertData(data);
}

void database::SelectAllPushTableData(){
    tableModel = new QSqlQueryModel;//定义一个数据库模型，指定父对象

    QString strSelectData = "select * from qtdata";
    tableModel->setQuery(strSelectData);

    ui->tableView->setModel(tableModel);
}

void database::UpdataToDataBase(QString Stemp,QString Shumi,QString Slight,QString Ssoil,QString Smq2,QString Srain)
{
    double val[6];

    val[0] = Stemp.toDouble();
    val[1] = Shumi.toDouble();
    val[2] = Slight.toDouble();

    val[3] = Ssoil.toDouble();
    val[4] = Smq2.toDouble();
    val[5] = Srain.toDouble();

    qDebug()<< "UpdataToDataBase: " << val[0]<<" "<<val[1]<<" "<<val[2]<<" "<<val[3]<<" "<<val[4]<<" "<<val[5]<<" "<<" ";

    //插入
    insertData(val);

    //查询并全部显示
    SelectAllPushTableData();

}

void database::on_exit_bt_clicked()
{
    this->close();
}

//插入数据
bool database::insertData(double val[6])
{
    QSqlQuery query;


     QString stInsertData = "insert into qtdata(curren_time, temp, humi, light, soil, mq2, rain) VALUES (?,?,?,?,?,?,?)";

    query.prepare(stInsertData);


    query.addBindValue(QDateTime::currentDateTime().addSecs(0).toString("yyyy-MM-dd hh:mm:ss"));

    query.addBindValue(val[0]);
    query.addBindValue(val[1]);
    query.addBindValue(val[2]);
    query.addBindValue(val[3]);
    query.addBindValue(val[4]);
    query.addBindValue(val[5]);
    qDebug()<< "insertData: " <<  QDateTime::currentDateTime().addSecs(0).toString("yyyy-MM-dd hh:mm:ss") << " " <<  val[0]<<" "<<val[1]<<" "<<val[2]<<" "<<val[3]<<" "<<val[4]<<" "<<val[5]<<" "<<" ";

    if(!query.exec())
    {
        qDebug()<< "query.exec() error: " << query.lastError();
    }
    return true;
}


//清空表
bool database::clearDBTable()
{
    QSqlQuery query;
    QString strClearDB = "delete from qtdata";
    query.prepare(strClearDB);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    return true;
}


//日期查询
void database::SelectData()
{
    tableModel = new QSqlQueryModel;//定义一个数据库模型，指定父对象

    QString startTime = ui->dateTimeEdit->text();
    QString endTime = ui->dateTimeEdit_2->text();

    //查询操作
    QString strSelectData = "select *from qtdata where curren_time between '"+startTime+"' and '"+endTime+"';";
    tableModel->setQuery(strSelectData);
    ui->tableView->setModel(tableModel);
}

database::~database()
{
    delete ui;
}


//退出


//查询按钮  ->查询指定日期
void database::on_select_data_bt_clicked()
{
    SelectData();
}

//显示所有
void database::on_displayAll_bt_clicked()
{
    SelectAllPushTableData();
}

//now
void database::on_now_bt_clicked()
{
    //当前时间
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime().addSecs(0));
}
//最近一天
void database::on_currDay_bt_clicked()
{
    //上一天
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(-3600*24));
   //当前时间
   ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime().addSecs(0));

   SelectData();
}
//最近三天
void database::on_currThDay_bt_clicked()
{
    //三天前天
   ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(-3600*24*3));
   //当前时间
   ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime().addSecs(0));

   SelectData();
}
//最近一周
void database::on_currWeek_bt_clicked()
{
    //七天前
   ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(-3600*24*7));
   //当前时间
   ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime().addSecs(0));

   SelectData();
}

//条件查询
void database::on_select_val_bt_clicked()
{
    //获取索引值
    QString strNum = ui->comboBox->currentText();

    //获取上下值
    QString downNum = ui->spinBox->text();
    QString upNum = ui->spinBox_2->text();

    //查询操作
    QString strSelectData = "select *from qtdata where "+strNum+" >= "+downNum+" && "+strNum+"<="+upNum+";";
    qDebug() << "on_select_val_bt_clicked: sql -> " << strSelectData;

    tableModel->setQuery(strSelectData);
    ui->tableView->setModel(tableModel);
}

//添加
/*
void database::on_add_bt_clicked()
{
    //插入数据
   // insertData();
    //查询并显示
    SelectAllPushTableData();
}*/
//清空表按钮
void database::on_clear_bt_clicked()
{
    clearDBTable();
    SelectAllPushTableData();
}

void database::on_export_result_bt_clicked()
{
    if (!tableModel) {
        QMessageBox::warning(this, "导出失败", "当前没有可导出的查询结果。");
        return;
    }

    if (tableModel->lastError().isValid()) {
        QMessageBox::warning(this, "导出失败",
                             "当前查询存在错误：\n" + tableModel->lastError().text());
        return;
    }

    // QSqlQueryModel 可能按需分批取数；导出前确保取完当前查询的全部结果。
    while (tableModel->canFetchMore())
        tableModel->fetchMore();

    const int rowCount = tableModel->rowCount();
    const int columnCount = tableModel->columnCount();
    if (rowCount == 0 || columnCount == 0) {
        QMessageBox::information(this, "没有数据", "当前查询没有可导出的记录。");
        return;
    }

    const QString suggestedName = QString("qtdata_%1.csv")
        .arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));
    QString fileName = QFileDialog::getSaveFileName(
        this, "导出当前查询结果", suggestedName, "CSV 文件 (*.csv)");
    if (fileName.isEmpty())
        return;
    if (!fileName.endsWith(".csv", Qt::CaseInsensitive))
        fileName += ".csv";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "导出失败",
                             "无法创建文件：\n" + file.errorString());
        return;
    }

    // UTF-8 BOM 便于 Windows Excel 正确识别中文。
    file.write("\xEF\xBB\xBF");
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    const auto csvField = [](QString value) {
        value.replace('"', "\"\"");
        return "\"" + value + "\"";
    };

    QStringList fields;
    fields.reserve(columnCount);
    for (int column = 0; column < columnCount; ++column)
        fields.append(csvField(tableModel->headerData(column, Qt::Horizontal).toString()));
    out << fields.join(',') << '\n';

    for (int row = 0; row < rowCount; ++row) {
        fields.clear();
        for (int column = 0; column < columnCount; ++column)
            fields.append(csvField(tableModel->data(tableModel->index(row, column)).toString()));
        out << fields.join(',') << '\n';
    }

    out.flush();
    if (out.status() != QTextStream::Ok || file.error() != QFileDevice::NoError) {
        QMessageBox::warning(this, "导出失败",
                             "写入 CSV 时发生错误：\n" + file.errorString());
        return;
    }

    QMessageBox::information(this, "导出成功",
                             QString("已导出 %1 条记录到：\n%2").arg(rowCount).arg(fileName));
}
