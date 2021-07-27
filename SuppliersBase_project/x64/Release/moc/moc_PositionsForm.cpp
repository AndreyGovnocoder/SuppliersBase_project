/****************************************************************************
** Meta object code from reading C++ file 'PositionsForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PositionsForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PositionsForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PositionsForm_t {
    QByteArrayData data[8];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PositionsForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PositionsForm_t qt_meta_stringdata_PositionsForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PositionsForm"
QT_MOC_LITERAL(1, 14, 26), // "positionsMenuRequestedSlot"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "pos"
QT_MOC_LITERAL(4, 46, 15), // "addPositionSlot"
QT_MOC_LITERAL(5, 62, 16), // "editPositionSlot"
QT_MOC_LITERAL(6, 79, 18), // "removePositionSlot"
QT_MOC_LITERAL(7, 98, 19) // "searchPositionsSlot"

    },
    "PositionsForm\0positionsMenuRequestedSlot\0"
    "\0pos\0addPositionSlot\0editPositionSlot\0"
    "removePositionSlot\0searchPositionsSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PositionsForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PositionsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PositionsForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionsMenuRequestedSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->addPositionSlot(); break;
        case 2: _t->editPositionSlot(); break;
        case 3: _t->removePositionSlot(); break;
        case 4: _t->searchPositionsSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PositionsForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_PositionsForm.data,
    qt_meta_data_PositionsForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PositionsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PositionsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PositionsForm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::PositionsForm"))
        return static_cast< Ui::PositionsForm*>(this);
    return QDialog::qt_metacast(_clname);
}

int PositionsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
