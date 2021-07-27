/****************************************************************************
** Meta object code from reading C++ file 'MainInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainInterface_t {
    QByteArrayData data[18];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainInterface_t qt_meta_stringdata_MainInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainInterface"
QT_MOC_LITERAL(1, 14, 15), // "addSupplierSlot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "editSupplierSlot"
QT_MOC_LITERAL(4, 48, 18), // "removeSupplierSlot"
QT_MOC_LITERAL(5, 67, 22), // "setSuppliersStatusSlot"
QT_MOC_LITERAL(6, 90, 26), // "suppliersMenuRequestedSlot"
QT_MOC_LITERAL(7, 117, 3), // "pos"
QT_MOC_LITERAL(8, 121, 25), // "contactsMenuRequestedSlot"
QT_MOC_LITERAL(9, 147, 21), // "openPositionsFormSlot"
QT_MOC_LITERAL(10, 169, 17), // "openAboutFormSlot"
QT_MOC_LITERAL(11, 187, 18), // "selectSupplierSlot"
QT_MOC_LITERAL(12, 206, 21), // "setSuppliersTableSlot"
QT_MOC_LITERAL(13, 228, 10), // "searchSlot"
QT_MOC_LITERAL(14, 239, 16), // "showPathToDBSlot"
QT_MOC_LITERAL(15, 256, 15), // "setPathToDBSlot"
QT_MOC_LITERAL(16, 272, 13), // "copyPhoneSlot"
QT_MOC_LITERAL(17, 286, 13) // "copyEmailSlot"

    },
    "MainInterface\0addSupplierSlot\0\0"
    "editSupplierSlot\0removeSupplierSlot\0"
    "setSuppliersStatusSlot\0"
    "suppliersMenuRequestedSlot\0pos\0"
    "contactsMenuRequestedSlot\0"
    "openPositionsFormSlot\0openAboutFormSlot\0"
    "selectSupplierSlot\0setSuppliersTableSlot\0"
    "searchSlot\0showPathToDBSlot\0setPathToDBSlot\0"
    "copyPhoneSlot\0copyEmailSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    0,   99,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addSupplierSlot(); break;
        case 1: _t->editSupplierSlot(); break;
        case 2: _t->removeSupplierSlot(); break;
        case 3: _t->setSuppliersStatusSlot(); break;
        case 4: _t->suppliersMenuRequestedSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->contactsMenuRequestedSlot((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->openPositionsFormSlot(); break;
        case 7: _t->openAboutFormSlot(); break;
        case 8: _t->selectSupplierSlot(); break;
        case 9: _t->setSuppliersTableSlot(); break;
        case 10: _t->searchSlot(); break;
        case 11: _t->showPathToDBSlot(); break;
        case 12: _t->setPathToDBSlot(); break;
        case 13: _t->copyPhoneSlot(); break;
        case 14: _t->copyEmailSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainInterface.data,
    qt_meta_data_MainInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainInterface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
