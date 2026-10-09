/****************************************************************************
** Meta object code from reading C++ file 'databaseworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../databaseworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databaseworker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS = QtMocHelpers::stringData(
    "DatabaseWorker",
    "databaseError",
    "",
    "message",
    "recordInserted",
    "initialize",
    "insertSensorData",
    "temp",
    "humi",
    "light",
    "soil",
    "mq2",
    "rain",
    "shutdown"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[15];
    char stringdata5[11];
    char stringdata6[17];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[6];
    char stringdata10[5];
    char stringdata11[4];
    char stringdata12[5];
    char stringdata13[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS_t qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "DatabaseWorker"
        QT_MOC_LITERAL(15, 13),  // "databaseError"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 7),  // "message"
        QT_MOC_LITERAL(38, 14),  // "recordInserted"
        QT_MOC_LITERAL(53, 10),  // "initialize"
        QT_MOC_LITERAL(64, 16),  // "insertSensorData"
        QT_MOC_LITERAL(81, 4),  // "temp"
        QT_MOC_LITERAL(86, 4),  // "humi"
        QT_MOC_LITERAL(91, 5),  // "light"
        QT_MOC_LITERAL(97, 4),  // "soil"
        QT_MOC_LITERAL(102, 3),  // "mq2"
        QT_MOC_LITERAL(106, 4),  // "rain"
        QT_MOC_LITERAL(111, 8)   // "shutdown"
    },
    "DatabaseWorker",
    "databaseError",
    "",
    "message",
    "recordInserted",
    "initialize",
    "insertSensorData",
    "temp",
    "humi",
    "light",
    "soil",
    "mq2",
    "rain",
    "shutdown"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabaseWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    0,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   48,    2, 0x0a,    4 /* Public */,
       6,    6,   49,    2, 0x0a,    5 /* Public */,
      13,    0,   62,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,   11,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DatabaseWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDatabaseWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DatabaseWorker, std::true_type>,
        // method 'databaseError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'recordInserted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initialize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insertSensorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'shutdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DatabaseWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->databaseError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->recordInserted(); break;
        case 2: _t->initialize(); break;
        case 3: _t->insertSensorData((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 4: _t->shutdown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatabaseWorker::*)(const QString & );
            if (_t _q_method = &DatabaseWorker::databaseError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DatabaseWorker::*)();
            if (_t _q_method = &DatabaseWorker::recordInserted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *DatabaseWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDatabaseWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DatabaseWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DatabaseWorker::databaseError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DatabaseWorker::recordInserted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
