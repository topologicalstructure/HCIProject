/****************************************************************************
** Meta object code from reading C++ file 'yesterdayworks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Easygtd/yesterdayworks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yesterdayworks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_yesterdayworks_t {
    QByteArrayData data[8];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_yesterdayworks_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_yesterdayworks_t qt_meta_stringdata_yesterdayworks = {
    {
QT_MOC_LITERAL(0, 0, 14), // "yesterdayworks"
QT_MOC_LITERAL(1, 15, 10), // "updateWork"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "id"
QT_MOC_LITERAL(4, 30, 8), // "nContent"
QT_MOC_LITERAL(5, 39, 10), // "deleteWork"
QT_MOC_LITERAL(6, 50, 10), // "finishWork"
QT_MOC_LITERAL(7, 61, 11) // "ModelUpdate"

    },
    "yesterdayworks\0updateWork\0\0id\0nContent\0"
    "deleteWork\0finishWork\0ModelUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_yesterdayworks[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,
       6,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void yesterdayworks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<yesterdayworks *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateWork((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->deleteWork((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->finishWork((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ModelUpdate(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject yesterdayworks::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_yesterdayworks.data,
    qt_meta_data_yesterdayworks,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *yesterdayworks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *yesterdayworks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_yesterdayworks.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int yesterdayworks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
