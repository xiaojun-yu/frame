/********************************************************************************
** Form generated from reading UI file 'deb.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEB_H
#define UI_DEB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deb
{
public:
    QPlainTextEdit *rec_edi;
    QLineEdit *send_edi;
    QPushButton *exit_bt;
    QPushButton *clear_bt;
    QPushButton *send_bt;
    QLabel *label;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_5;
    QLabel *temp_la;
    QLabel *humi_la;
    QLabel *lighticon;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *light_la;
    QLabel *soil_la;
    QLabel *mq2_la;
    QLabel *rain_la;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QPushButton *autoSimulation;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Deb)
    {
        if (Deb->objectName().isEmpty())
            Deb->setObjectName("Deb");
        Deb->resize(525, 617);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(16);
        Deb->setFont(font);
        Deb->setStyleSheet(QString::fromUtf8(""));
        rec_edi = new QPlainTextEdit(Deb);
        rec_edi->setObjectName("rec_edi");
        rec_edi->setGeometry(QRect(20, 40, 441, 271));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font1.setPointSize(11);
        rec_edi->setFont(font1);
        send_edi = new QLineEdit(Deb);
        send_edi->setObjectName("send_edi");
        send_edi->setGeometry(QRect(20, 330, 441, 61));
        send_edi->setFont(font1);
        send_edi->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        exit_bt = new QPushButton(Deb);
        exit_bt->setObjectName("exit_bt");
        exit_bt->setGeometry(QRect(470, 40, 35, 35));
        exit_bt->setStyleSheet(QString::fromUtf8("border-image: url(:/exit.png);"));
        clear_bt = new QPushButton(Deb);
        clear_bt->setObjectName("clear_bt");
        clear_bt->setGeometry(QRect(470, 270, 35, 35));
        clear_bt->setStyleSheet(QString::fromUtf8("border-image: url(:/clear_b.png);"));
        send_bt = new QPushButton(Deb);
        send_bt->setObjectName("send_bt");
        send_bt->setGeometry(QRect(470, 364, 35, 35));
        send_bt->setFont(font1);
        send_bt->setStyleSheet(QString::fromUtf8("border-image: url(://send.png);"));
        label = new QLabel(Deb);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 201, 31));
        pushButton_2 = new QPushButton(Deb);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 320, 35, 35));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/clearS.png);"));
        groupBox_5 = new QGroupBox(Deb);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(30, 420, 351, 181));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font2.setPointSize(13);
        groupBox_5->setFont(font2);
        groupBox_5->setAlignment(Qt::AlignCenter);
        temp_la = new QLabel(groupBox_5);
        temp_la->setObjectName("temp_la");
        temp_la->setGeometry(QRect(30, 80, 50, 16));
        temp_la->setFont(font1);
        humi_la = new QLabel(groupBox_5);
        humi_la->setObjectName("humi_la");
        humi_la->setGeometry(QRect(150, 80, 50, 16));
        humi_la->setFont(font1);
        lighticon = new QLabel(groupBox_5);
        lighticon->setObjectName("lighticon");
        lighticon->setGeometry(QRect(270, 30, 35, 35));
        lighticon->setStyleSheet(QString::fromUtf8("border-image: url(:/light.png);"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(270, 110, 35, 35));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/rain.png);"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(150, 110, 35, 35));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/mq2.png);"));
        light_la = new QLabel(groupBox_5);
        light_la->setObjectName("light_la");
        light_la->setGeometry(QRect(270, 80, 50, 16));
        light_la->setFont(font1);
        soil_la = new QLabel(groupBox_5);
        soil_la->setObjectName("soil_la");
        soil_la->setGeometry(QRect(30, 150, 50, 16));
        soil_la->setFont(font1);
        mq2_la = new QLabel(groupBox_5);
        mq2_la->setObjectName("mq2_la");
        mq2_la->setGeometry(QRect(150, 150, 50, 16));
        mq2_la->setFont(font1);
        rain_la = new QLabel(groupBox_5);
        rain_la->setObjectName("rain_la");
        rain_la->setGeometry(QRect(270, 150, 50, 16));
        rain_la->setFont(font1);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 30, 35, 35));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/humi.png);"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 30, 35, 35));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/temp.png);"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 110, 35, 35));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/humi_soil.png);"));
        autoSimulation = new QPushButton(Deb);
        autoSimulation->setObjectName("autoSimulation");
        autoSimulation->setGeometry(QRect(400, 460, 91, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font3.setPointSize(12);
        autoSimulation->setFont(font3);
        layoutWidget = new QWidget(Deb);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Deb);

        QMetaObject::connectSlotsByName(Deb);
    } // setupUi

    void retranslateUi(QWidget *Deb)
    {
        Deb->setWindowTitle(QCoreApplication::translate("Deb", "Form", nullptr));
        exit_bt->setText(QString());
        clear_bt->setText(QString());
        send_bt->setText(QString());
        label->setText(QCoreApplication::translate("Deb", "\350\260\203  \350\257\225  \347\225\214  \351\235\242", nullptr));
        pushButton_2->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("Deb", "\350\207\252\345\212\250\346\250\241\346\213\237\350\256\276\345\244\207\345\217\202\346\225\260 \351\227\264\351\232\2242\347\247\222", nullptr));
        temp_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        humi_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        lighticon->setText(QString());
        label_11->setText(QString());
        label_10->setText(QString());
        light_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        soil_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        mq2_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        rain_la->setText(QCoreApplication::translate("Deb", "N/A", nullptr));
        label_7->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        autoSimulation->setText(QCoreApplication::translate("Deb", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deb: public Ui_Deb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEB_H
