/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
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
    QByteArrayData data[57];
    char stringdata0[683];
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
QT_MOC_LITERAL(22, 160, 14), // "QVector<float>"
QT_MOC_LITERAL(23, 175, 1), // "n"
QT_MOC_LITERAL(24, 177, 16), // "ReceiveTranslate"
QT_MOC_LITERAL(25, 194, 2), // "dx"
QT_MOC_LITERAL(26, 197, 2), // "dy"
QT_MOC_LITERAL(27, 200, 13), // "ReceiveRotate"
QT_MOC_LITERAL(28, 214, 1), // "r"
QT_MOC_LITERAL(29, 216, 12), // "ReceiveScale"
QT_MOC_LITERAL(30, 229, 1), // "s"
QT_MOC_LITERAL(31, 231, 11), // "ReceiveClip"
QT_MOC_LITERAL(32, 243, 11), // "ResetParams"
QT_MOC_LITERAL(33, 255, 5), // "width"
QT_MOC_LITERAL(34, 261, 6), // "height"
QT_MOC_LITERAL(35, 268, 13), // "EllipseParams"
QT_MOC_LITERAL(36, 282, 12), // "RotateParams"
QT_MOC_LITERAL(37, 295, 11), // "ScaleParams"
QT_MOC_LITERAL(38, 307, 10), // "ClipParams"
QT_MOC_LITERAL(39, 318, 20), // "resetCanvasTriggered"
QT_MOC_LITERAL(40, 339, 19), // "saveCanvasTriggered"
QT_MOC_LITERAL(41, 359, 17), // "chooseIDTriggered"
QT_MOC_LITERAL(42, 377, 17), // "SetColorTriggered"
QT_MOC_LITERAL(43, 395, 18), // "drawPointTriggered"
QT_MOC_LITERAL(44, 414, 26), // "drawLineBresenhamTriggered"
QT_MOC_LITERAL(45, 441, 20), // "drawLineDDATriggered"
QT_MOC_LITERAL(46, 462, 29), // "drawPolygonBresenhamTriggered"
QT_MOC_LITERAL(47, 492, 23), // "drawPolygonDDATriggered"
QT_MOC_LITERAL(48, 516, 20), // "drawEllipseTriggered"
QT_MOC_LITERAL(49, 537, 24), // "drawCurveBezierTriggered"
QT_MOC_LITERAL(50, 562, 25), // "drawCurveBsplineTriggered"
QT_MOC_LITERAL(51, 588, 18), // "translateTriggered"
QT_MOC_LITERAL(52, 607, 15), // "rotateTriggered"
QT_MOC_LITERAL(53, 623, 14), // "scaleTriggered"
QT_MOC_LITERAL(54, 638, 13), // "clipTriggered"
QT_MOC_LITERAL(55, 652, 14), // "drawBufferLine"
QT_MOC_LITERAL(56, 667, 15) // "drawBufferCurve"

    },
    "Canvas\0ReceiveResetCanvas\0\0ReceiveSaveCanvas\0"
    "herit\0ReceiveSetColor\0R\0G\0B\0ReceiveDrawLine\0"
    "id\0x1\0y1\0x2\0y2\0algorithm\0ReceiveDrawEllipse\0"
    "x\0y\0rx\0ry\0ReceiveDrawCurve\0QVector<float>\0"
    "n\0ReceiveTranslate\0dx\0dy\0ReceiveRotate\0"
    "r\0ReceiveScale\0s\0ReceiveClip\0ResetParams\0"
    "width\0height\0EllipseParams\0RotateParams\0"
    "ScaleParams\0ClipParams\0resetCanvasTriggered\0"
    "saveCanvasTriggered\0chooseIDTriggered\0"
    "SetColorTriggered\0drawPointTriggered\0"
    "drawLineBresenhamTriggered\0"
    "drawLineDDATriggered\0drawPolygonBresenhamTriggered\0"
    "drawPolygonDDATriggered\0drawEllipseTriggered\0"
    "drawCurveBezierTriggered\0"
    "drawCurveBsplineTriggered\0translateTriggered\0"
    "rotateTriggered\0scaleTriggered\0"
    "clipTriggered\0drawBufferLine\0"
    "drawBufferCurve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x08 /* Private */,
       3,    1,  180,    2, 0x08 /* Private */,
       5,    3,  183,    2, 0x08 /* Private */,
       9,    6,  190,    2, 0x08 /* Private */,
      16,    5,  203,    2, 0x08 /* Private */,
      21,    5,  214,    2, 0x08 /* Private */,
      24,    3,  225,    2, 0x08 /* Private */,
      27,    4,  232,    2, 0x08 /* Private */,
      29,    4,  241,    2, 0x08 /* Private */,
      31,    6,  250,    2, 0x08 /* Private */,
      32,    2,  263,    2, 0x08 /* Private */,
      35,    5,  268,    2, 0x08 /* Private */,
      36,    4,  279,    2, 0x08 /* Private */,
      37,    4,  288,    2, 0x08 /* Private */,
      38,    6,  297,    2, 0x08 /* Private */,
      39,    0,  310,    2, 0x08 /* Private */,
      40,    0,  311,    2, 0x08 /* Private */,
      41,    0,  312,    2, 0x08 /* Private */,
      42,    0,  313,    2, 0x08 /* Private */,
      43,    0,  314,    2, 0x08 /* Private */,
      44,    0,  315,    2, 0x08 /* Private */,
      45,    0,  316,    2, 0x08 /* Private */,
      46,    0,  317,    2, 0x08 /* Private */,
      47,    0,  318,    2, 0x08 /* Private */,
      48,    0,  319,    2, 0x08 /* Private */,
      49,    0,  320,    2, 0x08 /* Private */,
      50,    0,  321,    2, 0x08 /* Private */,
      51,    0,  322,    2, 0x08 /* Private */,
      52,    0,  323,    2, 0x08 /* Private */,
      53,    0,  324,    2, 0x08 /* Private */,
      54,    0,  325,    2, 0x08 /* Private */,
      55,    6,  326,    2, 0x08 /* Private */,
      56,    5,  339,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, QMetaType::QString, QMetaType::Int,   10,   17,   18,   15,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float,   10,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   33,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   17,   18,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   10,   11,   12,   13,   14,   15,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, QMetaType::Int, QMetaType::QString,   10,   17,   18,   23,   15,

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
        case 5: _t->ReceiveDrawCurve((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<float>(*)>(_a[2])),(*reinterpret_cast< QVector<float>(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 6: _t->ReceiveTranslate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->ReceiveRotate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 8: _t->ReceiveScale((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 9: _t->ReceiveClip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 10: _t->ResetParams((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->EllipseParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 12: _t->RotateParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 13: _t->ScaleParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 14: _t->ClipParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 15: _t->resetCanvasTriggered(); break;
        case 16: _t->saveCanvasTriggered(); break;
        case 17: _t->chooseIDTriggered(); break;
        case 18: _t->SetColorTriggered(); break;
        case 19: _t->drawPointTriggered(); break;
        case 20: _t->drawLineBresenhamTriggered(); break;
        case 21: _t->drawLineDDATriggered(); break;
        case 22: _t->drawPolygonBresenhamTriggered(); break;
        case 23: _t->drawPolygonDDATriggered(); break;
        case 24: _t->drawEllipseTriggered(); break;
        case 25: _t->drawCurveBezierTriggered(); break;
        case 26: _t->drawCurveBsplineTriggered(); break;
        case 27: _t->translateTriggered(); break;
        case 28: _t->rotateTriggered(); break;
        case 29: _t->scaleTriggered(); break;
        case 30: _t->clipTriggered(); break;
        case 31: _t->drawBufferLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 32: _t->drawBufferCurve((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<float>(*)>(_a[2])),(*reinterpret_cast< QVector<float>(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
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
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
