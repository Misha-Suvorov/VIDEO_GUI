/****************************************************************************
** Meta object code from reading C++ file 'clickable.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../clickable.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clickable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14ClickableLabelE_t {};
} // unnamed namespace

template <> constexpr inline auto ClickableLabel::qt_create_metaobjectdata<qt_meta_tag_ZN14ClickableLabelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClickableLabel",
        "clickedAt",
        "",
        "QPoint",
        "pos",
        "held",
        "QPointF",
        "deltaAngle",
        "clicked",
        "pressed",
        "voltageChanged",
        "voltageH",
        "voltageV",
        "mouseHeld",
        "processClick"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clickedAt'
        QtMocHelpers::SignalData<void(QPoint)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'held'
        QtMocHelpers::SignalData<void(QPointF)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(QPointF)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'pressed'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'voltageChanged'
        QtMocHelpers::SignalData<void(float, float)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 11 }, { QMetaType::Float, 12 },
        }}),
        // Slot 'mouseHeld'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'processClick'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClickableLabel, qt_meta_tag_ZN14ClickableLabelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClickableLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ClickableLabelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ClickableLabelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14ClickableLabelE_t>.metaTypes,
    nullptr
} };

void ClickableLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClickableLabel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clickedAt((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->held((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 2: _t->clicked((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 3: _t->pressed(); break;
        case 4: _t->voltageChanged((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 5: _t->mouseHeld(); break;
        case 6: _t->processClick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClickableLabel::*)(QPoint )>(_a, &ClickableLabel::clickedAt, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClickableLabel::*)(QPointF )>(_a, &ClickableLabel::held, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClickableLabel::*)(QPointF )>(_a, &ClickableLabel::clicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClickableLabel::*)()>(_a, &ClickableLabel::pressed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClickableLabel::*)(float , float )>(_a, &ClickableLabel::voltageChanged, 4))
            return;
    }
}

const QMetaObject *ClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ClickableLabelE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClickableLabel::clickedAt(QPoint _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ClickableLabel::held(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ClickableLabel::clicked(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ClickableLabel::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClickableLabel::voltageChanged(float _t1, float _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
