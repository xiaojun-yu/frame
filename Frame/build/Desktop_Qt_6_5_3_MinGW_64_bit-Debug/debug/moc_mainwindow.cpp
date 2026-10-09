/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "saveSensorData",
    "",
    "temp",
    "humi",
    "light",
    "soil",
    "mq2",
    "rain",
    "on_pushButton_clicked",
    "ReData_Slot",
    "newConnection_Slot",
    "connected_Slot",
    "sendDebugData",
    "data",
    "on_sermode_clicked",
    "on_open_wifi_triggered",
    "on_led_triggered",
    "on_relay_triggered",
    "on_auto_hand_triggered",
    "on_debb_triggered",
    "on_exit_triggered",
    "on_charts1_big_clicked",
    "on_charts1_small_clicked",
    "on_charts1_rest_clicked",
    "on_horizontalSlider_valueChanged",
    "value",
    "on_checkBox_stateChanged",
    "arg1",
    "on_checkBox_2_stateChanged",
    "on_checkBox_3_stateChanged",
    "on_clear_yu_bt_clicked",
    "on_set_yu_bt_clicked",
    "on_set_light_bt_clicked",
    "on_charts1_big_2_clicked",
    "on_charts1_rest_2_clicked",
    "on_charts1_small_2_clicked",
    "on_pushButton_2_clicked",
    "on_checkBox_4_stateChanged",
    "on_data_triggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[80];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[5];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[4];
    char stringdata8[5];
    char stringdata9[22];
    char stringdata10[12];
    char stringdata11[19];
    char stringdata12[15];
    char stringdata13[14];
    char stringdata14[5];
    char stringdata15[19];
    char stringdata16[23];
    char stringdata17[17];
    char stringdata18[19];
    char stringdata19[23];
    char stringdata20[18];
    char stringdata21[18];
    char stringdata22[23];
    char stringdata23[25];
    char stringdata24[24];
    char stringdata25[33];
    char stringdata26[6];
    char stringdata27[25];
    char stringdata28[5];
    char stringdata29[27];
    char stringdata30[27];
    char stringdata31[23];
    char stringdata32[21];
    char stringdata33[24];
    char stringdata34[25];
    char stringdata35[26];
    char stringdata36[27];
    char stringdata37[24];
    char stringdata38[27];
    char stringdata39[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "saveSensorData"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "temp"
        QT_MOC_LITERAL(32, 4),  // "humi"
        QT_MOC_LITERAL(37, 5),  // "light"
        QT_MOC_LITERAL(43, 4),  // "soil"
        QT_MOC_LITERAL(48, 3),  // "mq2"
        QT_MOC_LITERAL(52, 4),  // "rain"
        QT_MOC_LITERAL(57, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(79, 11),  // "ReData_Slot"
        QT_MOC_LITERAL(91, 18),  // "newConnection_Slot"
        QT_MOC_LITERAL(110, 14),  // "connected_Slot"
        QT_MOC_LITERAL(125, 13),  // "sendDebugData"
        QT_MOC_LITERAL(139, 4),  // "data"
        QT_MOC_LITERAL(144, 18),  // "on_sermode_clicked"
        QT_MOC_LITERAL(163, 22),  // "on_open_wifi_triggered"
        QT_MOC_LITERAL(186, 16),  // "on_led_triggered"
        QT_MOC_LITERAL(203, 18),  // "on_relay_triggered"
        QT_MOC_LITERAL(222, 22),  // "on_auto_hand_triggered"
        QT_MOC_LITERAL(245, 17),  // "on_debb_triggered"
        QT_MOC_LITERAL(263, 17),  // "on_exit_triggered"
        QT_MOC_LITERAL(281, 22),  // "on_charts1_big_clicked"
        QT_MOC_LITERAL(304, 24),  // "on_charts1_small_clicked"
        QT_MOC_LITERAL(329, 23),  // "on_charts1_rest_clicked"
        QT_MOC_LITERAL(353, 32),  // "on_horizontalSlider_valueChanged"
        QT_MOC_LITERAL(386, 5),  // "value"
        QT_MOC_LITERAL(392, 24),  // "on_checkBox_stateChanged"
        QT_MOC_LITERAL(417, 4),  // "arg1"
        QT_MOC_LITERAL(422, 26),  // "on_checkBox_2_stateChanged"
        QT_MOC_LITERAL(449, 26),  // "on_checkBox_3_stateChanged"
        QT_MOC_LITERAL(476, 22),  // "on_clear_yu_bt_clicked"
        QT_MOC_LITERAL(499, 20),  // "on_set_yu_bt_clicked"
        QT_MOC_LITERAL(520, 23),  // "on_set_light_bt_clicked"
        QT_MOC_LITERAL(544, 24),  // "on_charts1_big_2_clicked"
        QT_MOC_LITERAL(569, 25),  // "on_charts1_rest_2_clicked"
        QT_MOC_LITERAL(595, 26),  // "on_charts1_small_2_clicked"
        QT_MOC_LITERAL(622, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(646, 26),  // "on_checkBox_4_stateChanged"
        QT_MOC_LITERAL(673, 17)   // "on_data_triggered"
    },
    "MainWindow",
    "saveSensorData",
    "",
    "temp",
    "humi",
    "light",
    "soil",
    "mq2",
    "rain",
    "on_pushButton_clicked",
    "ReData_Slot",
    "newConnection_Slot",
    "connected_Slot",
    "sendDebugData",
    "data",
    "on_sermode_clicked",
    "on_open_wifi_triggered",
    "on_led_triggered",
    "on_relay_triggered",
    "on_auto_hand_triggered",
    "on_debb_triggered",
    "on_exit_triggered",
    "on_charts1_big_clicked",
    "on_charts1_small_clicked",
    "on_charts1_rest_clicked",
    "on_horizontalSlider_valueChanged",
    "value",
    "on_checkBox_stateChanged",
    "arg1",
    "on_checkBox_2_stateChanged",
    "on_checkBox_3_stateChanged",
    "on_clear_yu_bt_clicked",
    "on_set_yu_bt_clicked",
    "on_set_light_bt_clicked",
    "on_charts1_big_2_clicked",
    "on_charts1_rest_2_clicked",
    "on_charts1_small_2_clicked",
    "on_pushButton_2_clicked",
    "on_checkBox_4_stateChanged",
    "on_data_triggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,  188,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  201,    2, 0x08,    8 /* Private */,
      10,    0,  202,    2, 0x08,    9 /* Private */,
      11,    0,  203,    2, 0x08,   10 /* Private */,
      12,    0,  204,    2, 0x08,   11 /* Private */,
      13,    1,  205,    2, 0x08,   12 /* Private */,
      15,    0,  208,    2, 0x08,   14 /* Private */,
      16,    0,  209,    2, 0x08,   15 /* Private */,
      17,    0,  210,    2, 0x08,   16 /* Private */,
      18,    0,  211,    2, 0x08,   17 /* Private */,
      19,    0,  212,    2, 0x08,   18 /* Private */,
      20,    0,  213,    2, 0x08,   19 /* Private */,
      21,    0,  214,    2, 0x08,   20 /* Private */,
      22,    0,  215,    2, 0x08,   21 /* Private */,
      23,    0,  216,    2, 0x08,   22 /* Private */,
      24,    0,  217,    2, 0x08,   23 /* Private */,
      25,    1,  218,    2, 0x08,   24 /* Private */,
      27,    1,  221,    2, 0x08,   26 /* Private */,
      29,    1,  224,    2, 0x08,   28 /* Private */,
      30,    1,  227,    2, 0x08,   30 /* Private */,
      31,    0,  230,    2, 0x08,   32 /* Private */,
      32,    0,  231,    2, 0x08,   33 /* Private */,
      33,    0,  232,    2, 0x08,   34 /* Private */,
      34,    0,  233,    2, 0x08,   35 /* Private */,
      35,    0,  234,    2, 0x08,   36 /* Private */,
      36,    0,  235,    2, 0x08,   37 /* Private */,
      37,    0,  236,    2, 0x08,   38 /* Private */,
      38,    1,  237,    2, 0x08,   39 /* Private */,
      39,    0,  240,    2, 0x08,   41 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'saveSensorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ReData_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'newConnection_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connected_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendDebugData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_sermode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_open_wifi_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_led_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_relay_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_auto_hand_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_debb_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_big_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_small_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_rest_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_2_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_3_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clear_yu_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_set_yu_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_set_light_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_big_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_rest_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_charts1_small_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_4_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_data_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveSensorData((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->ReData_Slot(); break;
        case 3: _t->newConnection_Slot(); break;
        case 4: _t->connected_Slot(); break;
        case 5: _t->sendDebugData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_sermode_clicked(); break;
        case 7: _t->on_open_wifi_triggered(); break;
        case 8: _t->on_led_triggered(); break;
        case 9: _t->on_relay_triggered(); break;
        case 10: _t->on_auto_hand_triggered(); break;
        case 11: _t->on_debb_triggered(); break;
        case 12: _t->on_exit_triggered(); break;
        case 13: _t->on_charts1_big_clicked(); break;
        case 14: _t->on_charts1_small_clicked(); break;
        case 15: _t->on_charts1_rest_clicked(); break;
        case 16: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_checkBox_2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_checkBox_3_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_clear_yu_bt_clicked(); break;
        case 21: _t->on_set_yu_bt_clicked(); break;
        case 22: _t->on_set_light_bt_clicked(); break;
        case 23: _t->on_charts1_big_2_clicked(); break;
        case 24: _t->on_charts1_rest_2_clicked(); break;
        case 25: _t->on_charts1_small_2_clicked(); break;
        case 26: _t->on_pushButton_2_clicked(); break;
        case 27: _t->on_checkBox_4_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_data_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(double , double , double , double , double , double );
            if (_t _q_method = &MainWindow::saveSensorData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::saveSensorData(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
