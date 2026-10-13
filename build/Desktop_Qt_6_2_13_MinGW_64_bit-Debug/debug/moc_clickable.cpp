/****************************************************************************
** Meta object code from reading C++ file 'clickable.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../clickable.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clickable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClickableLabel_t {
    uint offsetsAndSizes[26];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ClickableLabel_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ClickableLabel_t qt_meta_stringdata_ClickableLabel = {
    {
        QT_MOC_LITERAL(0, 14),  // "ClickableLabel"
        QT_MOC_LITERAL(15, 9),  // "clickedAt"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 3),  // "pos"
        QT_MOC_LITERAL(30, 4),  // "held"
        QT_MOC_LITERAL(35, 10),  // "deltaAngle"
        QT_MOC_LITERAL(46, 7),  // "clicked"
        QT_MOC_LITERAL(54, 7),  // "pressed"
        QT_MOC_LITERAL(62, 14),  // "voltageChanged"
        QT_MOC_LITERAL(77, 8),  // "voltageH"
        QT_MOC_LITERAL(86, 8),  // "voltageV"
        QT_MOC_LITERAL(95, 9),  // "mouseHeld"
        QT_MOC_LITERAL(105, 12)   // "processClick"
    },
    "ClickableLabel\0clickedAt\0\0pos\0held\0"
    "deltaAngle\0clicked\0pressed\0voltageChanged\0"
    "voltageH\0voltageV\0mouseHeld\0processClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClickableLabel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,
       6,    1,   62,    2, 0x06,    5 /* Public */,
       7,    0,   65,    2, 0x06,    7 /* Public */,
       8,    2,   66,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   71,    2, 0x08,   11 /* Private */,
      12,    0,   72,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPointF,    5,
    QMetaType::Void, QMetaType::QPointF,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClickableLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClickableLabel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clickedAt((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->held((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 2: _t->clicked((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 3: _t->pressed(); break;
        case 4: _t->voltageChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 5: _t->mouseHeld(); break;
        case 6: _t->processClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClickableLabel::*)(QPoint );
            if (_t _q_method = &ClickableLabel::clickedAt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClickableLabel::*)(QPointF );
            if (_t _q_method = &ClickableLabel::held; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClickableLabel::*)(QPointF );
            if (_t _q_method = &ClickableLabel::clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClickableLabel::*)();
            if (_t _q_method = &ClickableLabel::pressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClickableLabel::*)(float , float );
            if (_t _q_method = &ClickableLabel::voltageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ClickableLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_ClickableLabel.offsetsAndSizes,
    qt_meta_data_ClickableLabel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClickableLabel_t
, QtPrivate::TypeAndForceComplete<ClickableLabel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPointF, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPointF, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClickableLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int ClickableLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClickableLabel::clickedAt(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClickableLabel::held(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClickableLabel::clicked(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClickableLabel::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClickableLabel::voltageChanged(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
