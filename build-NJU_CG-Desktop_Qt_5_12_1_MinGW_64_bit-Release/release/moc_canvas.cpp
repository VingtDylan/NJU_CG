/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NJU_CG/canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    QByteArrayData data[30];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Canvas"
QT_MOC_LITERAL(1, 7, 18), // "ReceiveResetCanvas"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "ReceiveSaveCanvas"
QT_MOC_LITERAL(4, 45, 5), // "herit"
QT_MOC_LITERAL(5, 51, 15), // "ReceiveSetColor"
QT_MOC_LITERAL(6, 67, 1), // "R"
QT_MOC_LITERAL(7, 69, 1), // "G"
QT_MOC_LITERAL(8, 71, 1), // "B"
QT_MOC_LITERAL(9, 73, 15), // "ReceiveDrawLine"
QT_MOC_LITERAL(10, 89, 2), // "id"
QT_MOC_LITERAL(11, 92, 2), // "x1"
QT_MOC_LITERAL(12, 95, 2), // "y1"
QT_MOC_LITERAL(13, 98, 2), // "x2"
QT_MOC_LITERAL(14, 101, 2), // "y2"
QT_MOC_LITERAL(15, 104, 9), // "algorithm"
QT_MOC_LITERAL(16, 114, 18), // "ReceiveDrawEllipse"
QT_MOC_LITERAL(17, 133, 1), // "x"
QT_MOC_LITERAL(18, 135, 1), // "y"
QT_MOC_LITERAL(19, 137, 2), // "rx"
QT_MOC_LITERAL(20, 140, 2), // "ry"
QT_MOC_LITERAL(21, 143, 16), // "ReceiveDrawCurve"
QT_MOC_LITERAL(22, 160, 16), // "ReceiveTranslate"
QT_MOC_LITERAL(23, 177, 2), // "dx"
QT_MOC_LITERAL(24, 180, 2), // "dy"
QT_MOC_LITERAL(25, 183, 13), // "ReceiveRotate"
QT_MOC_LITERAL(26, 197, 1), // "r"
QT_MOC_LITERAL(27, 199, 12), // "ReceiveScale"
QT_MOC_LITERAL(28, 212, 1), // "s"
QT_MOC_LITERAL(29, 214, 11) // "ReceiveClip"

    },
    "Canvas\0ReceiveResetCanvas\0\0ReceiveSaveCanvas\0"
    "herit\0ReceiveSetColor\0R\0G\0B\0ReceiveDrawLine\0"
    "id\0x1\0y1\0x2\0y2\0algorithm\0ReceiveDrawEllipse\0"
    "x\0y\0rx\0ry\0ReceiveDrawCurve\0ReceiveTranslate\0"
    "dx\0dy\0ReceiveRotate\0r\0ReceiveScale\0s\0"
    "ReceiveClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    3,   68,    2, 0x08 /* Private */,
       9,    6,   75,    2, 0x08 /* Private */,
      16,    5,   88,    2, 0x08 /* Private */,
      21,    0,   99,    2, 0x08 /* Private */,
      22,    3,  100,    2, 0x08 /* Private */,
      25,    4,  107,    2, 0x08 /* Private */,
      27,    4,  116,    2, 0x08 /* Private */,
      29,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float,   10,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   28,
    QMetaType::Void,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveResetCanvas(); break;
        case 1: _t->ReceiveSaveCanvas((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ReceiveSetColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->ReceiveDrawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 4: _t->ReceiveDrawEllipse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 5: _t->ReceiveDrawCurve(); break;
        case 6: _t->ReceiveTranslate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->ReceiveRotate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 8: _t->ReceiveScale((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 9: _t->ReceiveClip(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Canvas::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Canvas.data,
    qt_meta_data_Canvas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
