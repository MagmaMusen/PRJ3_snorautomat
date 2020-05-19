/****************************************************************************
** Meta object code from reading C++ file 'orderropelengthwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI2/orderropelengthwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderropelengthwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_orderRopeLengthWindow_t {
    QByteArrayData data[10];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_orderRopeLengthWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_orderRopeLengthWindow_t qt_meta_stringdata_orderRopeLengthWindow = {
    {
QT_MOC_LITERAL(0, 0, 21), // "orderRopeLengthWindow"
QT_MOC_LITERAL(1, 22, 20), // "valueChangedPositive"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 20), // "valueChangedNegative"
QT_MOC_LITERAL(4, 65, 10), // "valueReset"
QT_MOC_LITERAL(5, 76, 17), // "openPaymentWindow"
QT_MOC_LITERAL(6, 94, 25), // "buttonFivePositiveClicked"
QT_MOC_LITERAL(7, 120, 25), // "buttonFiveNegativeClicked"
QT_MOC_LITERAL(8, 146, 19), // "buttonCancelClicked"
QT_MOC_LITERAL(9, 166, 14) // "sendRopeLength"

    },
    "orderRopeLengthWindow\0valueChangedPositive\0"
    "\0valueChangedNegative\0valueReset\0"
    "openPaymentWindow\0buttonFivePositiveClicked\0"
    "buttonFiveNegativeClicked\0buttonCancelClicked\0"
    "sendRopeLength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_orderRopeLengthWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void orderRopeLengthWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<orderRopeLengthWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChangedPositive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valueChangedNegative((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->valueReset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->openPaymentWindow(); break;
        case 4: _t->buttonFivePositiveClicked(); break;
        case 5: _t->buttonFiveNegativeClicked(); break;
        case 6: _t->buttonCancelClicked(); break;
        case 7: _t->sendRopeLength(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (orderRopeLengthWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&orderRopeLengthWindow::valueChangedPositive)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (orderRopeLengthWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&orderRopeLengthWindow::valueChangedNegative)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (orderRopeLengthWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&orderRopeLengthWindow::valueReset)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject orderRopeLengthWindow::staticMetaObject = { {
    &QWizardPage::staticMetaObject,
    qt_meta_stringdata_orderRopeLengthWindow.data,
    qt_meta_data_orderRopeLengthWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *orderRopeLengthWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *orderRopeLengthWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_orderRopeLengthWindow.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int orderRopeLengthWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void orderRopeLengthWindow::valueChangedPositive(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void orderRopeLengthWindow::valueChangedNegative(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void orderRopeLengthWindow::valueReset(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
