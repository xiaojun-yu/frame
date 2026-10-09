/****************************************************************************
** Meta object code from reading C++ file 'deb.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../deb.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deb.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDebENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDebENDCLASS = QtMocHelpers::stringData(
    "Deb",
    "sendData",
    "",
    "data",
    "on_exit_bt_clicked",
    "on_clear_bt_clicked",
    "on_pushButton_2_clicked",
    "on_send_bt_clicked",
    "on_autoSimulation_clicked",
    "timer_simulate_slot"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDebENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[4];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[19];
    char stringdata5[20];
    char stringdata6[24];
    char stringdata7[19];
    char stringdata8[26];
    char stringdata9[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDebENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDebENDCLASS_t qt_meta_stringdata_CLASSDebENDCLASS = {
    {
        QT_MOC_LITERAL(0, 3),  // "Deb"
        QT_MOC_LITERAL(4, 8),  // "sendData"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 4),  // "data"
        QT_MOC_LITERAL(19, 18),  // "on_exit_bt_clicked"
        QT_MOC_LITERAL(38, 19),  // "on_clear_bt_clicked"
        QT_MOC_LITERAL(58, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(82, 18),  // "on_send_bt_clicked"
        QT_MOC_LITERAL(101, 25),  // "on_autoSimulation_clicked"
        QT_MOC_LITERAL(127, 19)   // "timer_simulate_slot"
    },
    "Deb",
    "sendData",
    "",
    "data",
    "on_exit_bt_clicked",
    "on_clear_bt_clicked",
    "on_pushButton_2_clicked",
    "on_send_bt_clicked",
    "on_autoSimulation_clicked",
    "timer_simulate_slot"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDebENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   59,    2, 0x08,    3 /* Private */,
       5,    0,   60,    2, 0x08,    4 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Deb::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSDebENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDebENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDebENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Deb, std::true_type>,
        // method 'sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_exit_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_send_bt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_autoSimulation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timer_simulate_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Deb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Deb *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_exit_bt_clicked(); break;
        case 2: _t->on_clear_bt_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_send_bt_clicked(); break;
        case 5: _t->on_autoSimulation_clicked(); break;
        case 6: _t->timer_simulate_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Deb::*)(const QString & );
            if (_t _q_method = &Deb::sendData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Deb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Deb::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDebENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Deb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Deb::sendData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
