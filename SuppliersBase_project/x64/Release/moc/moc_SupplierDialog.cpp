/****************************************************************************
** Meta object code from reading C++ file 'SupplierDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SupplierDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SupplierDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SupplierDialog_t {
    QByteArrayData data[12];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SupplierDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SupplierDialog_t qt_meta_stringdata_SupplierDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SupplierDialog"
QT_MOC_LITERAL(1, 15, 10), // "acceptSlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 25), // "contactsMenuRequestedSlot"
QT_MOC_LITERAL(4, 53, 3), // "pos"
QT_MOC_LITERAL(5, 57, 22), // "addPositionToTableSlot"
QT_MOC_LITERAL(6, 80, 27), // "removePositionFromTableSlot"
QT_MOC_LITERAL(7, 108, 14), // "addContactSlot"
QT_MOC_LITERAL(8, 123, 15), // "editContactSlot"
QT_MOC_LITERAL(9, 139, 17), // "removeContactSlot"
QT_MOC_LITERAL(10, 157, 21), // "openPositionsFormSlot"
QT_MOC_LITERAL(11, 179, 18) // "addNewPositionSlot"

    },
    "SupplierDialog\0acceptSlot\0\0"
    "contactsMenuRequestedSlot\0pos\0"
    "addPositionToTableSlot\0"
    "removePositionFromTableSlot\0addContactSlot\0"
    "editContactSlot\0removeContactSlot\0"
    "openPositionsFormSlot\0addNewPositionSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SupplierDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SupplierDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SupplierDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->acceptSlot(); break;
        case 1: _t->contactsMenuRequestedSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->addPositionToTableSlot(); break;
        case 3: _t->removePositionFromTableSlot(); break;
        case 4: _t->addContactSlot(); break;
        case 5: _t->editContactSlot(); break;
        case 6: _t->removeContactSlot(); break;
        case 7: _t->openPositionsFormSlot(); break;
        case 8: _t->addNewPositionSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SupplierDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SupplierDialog.data,
    qt_meta_data_SupplierDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SupplierDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupplierDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SupplierDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::SupplierDialog"))
        return static_cast< Ui::SupplierDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int SupplierDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE