#ifndef DEB_H
#define DEB_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Deb;
}
//class MainWindow;

class Deb : public QWidget
{
    Q_OBJECT

public:
    //Ui::Deb *ui;
    explicit Deb(QWidget *parent = nullptr);
    ~Deb();
    void DisplayData(QString qstring);

signals:
    void sendData(const QString &data);
protected:
    // 重写 closeEvent 函数来处理关闭事件
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_exit_bt_clicked();

    void on_clear_bt_clicked();

    void on_pushButton_2_clicked();

    void on_send_bt_clicked();

    void on_autoSimulation_clicked();
    void timer_simulate_slot();

private:
    Ui::Deb *ui;
    bool auto_simulate_running = false;
    QTimer *timer_simulate = nullptr; //默认两秒发送生成一次数据
};


#endif // DEB_H
