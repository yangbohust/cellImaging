/****************************************************************************
** Meta object code from reading C++ file 'inputwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inputwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InputWidget_t {
    QByteArrayData data[9];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputWidget_t qt_meta_stringdata_InputWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "InputWidget"
QT_MOC_LITERAL(1, 12, 17), // "on_submit_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(4, 49, 16), // "on_query_clicked"
QT_MOC_LITERAL(5, 66, 18), // "on_viewAll_clicked"
QT_MOC_LITERAL(6, 85, 20), // "on_ascending_clicked"
QT_MOC_LITERAL(7, 106, 21), // "on_descending_clicked"
QT_MOC_LITERAL(8, 128, 17) // "on_delete_clicked"

    },
    "InputWidget\0on_submit_clicked\0\0"
    "on_cancel_clicked\0on_query_clicked\0"
    "on_viewAll_clicked\0on_ascending_clicked\0"
    "on_descending_clicked\0on_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InputWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputWidget *_t = static_cast<InputWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_submit_clicked(); break;
        case 1: _t->on_cancel_clicked(); break;
        case 2: _t->on_query_clicked(); break;
        case 3: _t->on_viewAll_clicked(); break;
        case 4: _t->on_ascending_clicked(); break;
        case 5: _t->on_descending_clicked(); break;
        case 6: _t->on_delete_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject InputWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InputWidget.data,
      qt_meta_data_InputWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InputWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InputWidget.stringdata0))
        return static_cast<void*>(const_cast< InputWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InputWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
