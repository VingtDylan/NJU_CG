/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NJU_CG/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[32];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "SendListCommand"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "commandlists"
QT_MOC_LITERAL(4, 41, 15), // "SendResetCanvas"
QT_MOC_LITERAL(5, 57, 14), // "SendSaveCanvas"
QT_MOC_LITERAL(6, 72, 3), // "str"
QT_MOC_LITERAL(7, 76, 12), // "SendSetColor"
QT_MOC_LITERAL(8, 89, 1), // "R"
QT_MOC_LITERAL(9, 91, 1), // "G"
QT_MOC_LITERAL(10, 93, 1), // "B"
QT_MOC_LITERAL(11, 95, 12), // "SendDrawLine"
QT_MOC_LITERAL(12, 108, 2), // "id"
QT_MOC_LITERAL(13, 111, 2), // "x1"
QT_MOC_LITERAL(14, 114, 2), // "y1"
QT_MOC_LITERAL(15, 117, 2), // "x2"
QT_MOC_LITERAL(16, 120, 2), // "y2"
QT_MOC_LITERAL(17, 123, 9), // "algorithm"
QT_MOC_LITERAL(18, 133, 15), // "SendDrawPolygon"
QT_MOC_LITERAL(19, 149, 15), // "SendDrawEllipse"
QT_MOC_LITERAL(20, 165, 1), // "x"
QT_MOC_LITERAL(21, 167, 1), // "y"
QT_MOC_LITERAL(22, 169, 2), // "rx"
QT_MOC_LITERAL(23, 172, 2), // "ry"
QT_MOC_LITERAL(24, 175, 13), // "SendDrawCurve"
QT_MOC_LITERAL(25, 189, 13), // "SendTranslate"
QT_MOC_LITERAL(26, 203, 10), // "SendRotate"
QT_MOC_LITERAL(27, 214, 9), // "SendScale"
QT_MOC_LITERAL(28, 224, 8), // "SendClip"
QT_MOC_LITERAL(29, 233, 4), // "open"
QT_MOC_LITERAL(30, 238, 11), // "ReadCommand"
QT_MOC_LITERAL(31, 250, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0SendListCommand\0\0commandlists\0"
    "SendResetCanvas\0SendSaveCanvas\0str\0"
    "SendSetColor\0R\0G\0B\0SendDrawLine\0id\0"
    "x1\0y1\0x2\0y2\0algorithm\0SendDrawPolygon\0"
    "SendDrawEllipse\0x\0y\0rx\0ry\0SendDrawCurve\0"
    "SendTranslate\0SendRotate\0SendScale\0"
    "SendClip\0open\0ReadCommand\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,
       7,    3,   96,    2, 0x06 /* Public */,
      11,    6,  103,    2, 0x06 /* Public */,
      18,    0,  116,    2, 0x06 /* Public */,
      19,    5,  117,    2, 0x06 /* Public */,
      24,    0,  128,    2, 0x06 /* Public */,
      25,    0,  129,    2, 0x06 /* Public */,
      26,    0,  130,    2, 0x06 /* Public */,
      27,    0,  131,    2, 0x06 /* Public */,
      28,    0,  132,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      29,    0,  133,    2, 0x08 /* Private */,
      30,    0,  134,    2, 0x08 /* Private */,
      31,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QString,   12,   13,   14,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   12,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendListCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendResetCanvas(); break;
        case 2: _t->SendSaveCanvas((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SendSetColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->SendDrawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 5: _t->SendDrawPolygon(); break;
        case 6: _t->SendDrawEllipse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 7: _t->SendDrawCurve(); break;
        case 8: _t->SendTranslate(); break;
        case 9: _t->SendRotate(); break;
        case 10: _t->SendScale(); break;
        case 11: _t->SendClip(); break;
        case 12: _t->open(); break;
        case 13: _t->ReadCommand(); break;
        case 14: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendListCommand)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendResetCanvas)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSaveCanvas)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendSetColor)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , float , float , float , float , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendDrawLine)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendDrawPolygon)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , float , float , float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendDrawEllipse)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendDrawCurve)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendTranslate)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendRotate)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendScale)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SendClip)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MainWindow::SendListCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::SendResetCanvas()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::SendSaveCanvas(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::SendSetColor(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::SendDrawLine(int _t1, float _t2, float _t3, float _t4, float _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::SendDrawPolygon()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::SendDrawEllipse(int _t1, float _t2, float _t3, float _t4, float _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::SendDrawCurve()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::SendTranslate()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::SendRotate()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::SendScale()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::SendClip()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
