/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.6. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVideoThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVideoThreadENDCLASS = QtMocHelpers::stringData(
    "VideoThread",
    "frameReady",
    "",
    "image"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVideoThreadENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVideoThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVideoThreadENDCLASS_t qt_meta_stringdata_CLASSVideoThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "VideoThread"
        QT_MOC_LITERAL(12, 10),  // "frameReady"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5)   // "image"
    },
    "VideoThread",
    "frameReady",
    "",
    "image"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject VideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSVideoThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVideoThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVideoThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VideoThread, std::true_type>,
        // method 'frameReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>
    >,
    nullptr
} };

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->frameReady((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoThread::*)(const QImage & );
            if (_t _q_method = &VideoThread::frameReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVideoThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::frameReady(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "displayFrame1",
    "",
    "image",
    "displayFrame2",
    "on_l_vid_turn_clicked",
    "on_r_vid_turn_clicked",
    "on_switch_vid_clicked",
    "on_start_b_clicked",
    "on_stop_b_2_clicked",
    "onHorizontMarkerChanged",
    "text",
    "onVerticalMarkerChanged",
    "on_pointer_b_clicked",
    "on_start_range_b_clicked",
    "on_break_range_b_clicked",
    "onMeasureModeChanged",
    "index",
    "onFrequencyModeChanged",
    "on_laser_act_b_clicked",
    "on_pulse_b_clicked",
    "on_term_control_b_clicked",
    "on_get_frequency_clicked",
    "on_get_stanag_clicked",
    "on_frequency_mode_currentIndexChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[50];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[22];
    char stringdata6[22];
    char stringdata7[22];
    char stringdata8[19];
    char stringdata9[20];
    char stringdata10[24];
    char stringdata11[5];
    char stringdata12[24];
    char stringdata13[21];
    char stringdata14[25];
    char stringdata15[25];
    char stringdata16[21];
    char stringdata17[6];
    char stringdata18[23];
    char stringdata19[23];
    char stringdata20[19];
    char stringdata21[26];
    char stringdata22[25];
    char stringdata23[22];
    char stringdata24[38];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "displayFrame1"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "image"
        QT_MOC_LITERAL(32, 13),  // "displayFrame2"
        QT_MOC_LITERAL(46, 21),  // "on_l_vid_turn_clicked"
        QT_MOC_LITERAL(68, 21),  // "on_r_vid_turn_clicked"
        QT_MOC_LITERAL(90, 21),  // "on_switch_vid_clicked"
        QT_MOC_LITERAL(112, 18),  // "on_start_b_clicked"
        QT_MOC_LITERAL(131, 19),  // "on_stop_b_2_clicked"
        QT_MOC_LITERAL(151, 23),  // "onHorizontMarkerChanged"
        QT_MOC_LITERAL(175, 4),  // "text"
        QT_MOC_LITERAL(180, 23),  // "onVerticalMarkerChanged"
        QT_MOC_LITERAL(204, 20),  // "on_pointer_b_clicked"
        QT_MOC_LITERAL(225, 24),  // "on_start_range_b_clicked"
        QT_MOC_LITERAL(250, 24),  // "on_break_range_b_clicked"
        QT_MOC_LITERAL(275, 20),  // "onMeasureModeChanged"
        QT_MOC_LITERAL(296, 5),  // "index"
        QT_MOC_LITERAL(302, 22),  // "onFrequencyModeChanged"
        QT_MOC_LITERAL(325, 22),  // "on_laser_act_b_clicked"
        QT_MOC_LITERAL(348, 18),  // "on_pulse_b_clicked"
        QT_MOC_LITERAL(367, 25),  // "on_term_control_b_clicked"
        QT_MOC_LITERAL(393, 24),  // "on_get_frequency_clicked"
        QT_MOC_LITERAL(418, 21),  // "on_get_stanag_clicked"
        QT_MOC_LITERAL(440, 37)   // "on_frequency_mode_currentInde..."
    },
    "MainWindow",
    "displayFrame1",
    "",
    "image",
    "displayFrame2",
    "on_l_vid_turn_clicked",
    "on_r_vid_turn_clicked",
    "on_switch_vid_clicked",
    "on_start_b_clicked",
    "on_stop_b_2_clicked",
    "onHorizontMarkerChanged",
    "text",
    "onVerticalMarkerChanged",
    "on_pointer_b_clicked",
    "on_start_range_b_clicked",
    "on_break_range_b_clicked",
    "onMeasureModeChanged",
    "index",
    "onFrequencyModeChanged",
    "on_laser_act_b_clicked",
    "on_pulse_b_clicked",
    "on_term_control_b_clicked",
    "on_get_frequency_clicked",
    "on_get_stanag_clicked",
    "on_frequency_mode_currentIndexChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x08,    1 /* Private */,
       4,    1,  137,    2, 0x08,    3 /* Private */,
       5,    0,  140,    2, 0x08,    5 /* Private */,
       6,    0,  141,    2, 0x08,    6 /* Private */,
       7,    0,  142,    2, 0x08,    7 /* Private */,
       8,    0,  143,    2, 0x08,    8 /* Private */,
       9,    0,  144,    2, 0x08,    9 /* Private */,
      10,    1,  145,    2, 0x08,   10 /* Private */,
      12,    1,  148,    2, 0x08,   12 /* Private */,
      13,    0,  151,    2, 0x08,   14 /* Private */,
      14,    0,  152,    2, 0x08,   15 /* Private */,
      15,    0,  153,    2, 0x08,   16 /* Private */,
      16,    1,  154,    2, 0x08,   17 /* Private */,
      18,    1,  157,    2, 0x08,   19 /* Private */,
      19,    0,  160,    2, 0x08,   21 /* Private */,
      20,    0,  161,    2, 0x08,   22 /* Private */,
      21,    0,  162,    2, 0x08,   23 /* Private */,
      22,    0,  163,    2, 0x08,   24 /* Private */,
      23,    0,  164,    2, 0x08,   25 /* Private */,
      24,    1,  165,    2, 0x08,   26 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'displayFrame1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'displayFrame2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'on_l_vid_turn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_r_vid_turn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_switch_vid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_start_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stop_b_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHorizontMarkerChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onVerticalMarkerChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pointer_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_start_range_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_break_range_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMeasureModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onFrequencyModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_laser_act_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pulse_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_term_control_b_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_get_frequency_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_get_stanag_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_frequency_mode_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->displayFrame1((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->displayFrame2((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->on_l_vid_turn_clicked(); break;
        case 3: _t->on_r_vid_turn_clicked(); break;
        case 4: _t->on_switch_vid_clicked(); break;
        case 5: _t->on_start_b_clicked(); break;
        case 6: _t->on_stop_b_2_clicked(); break;
        case 7: _t->onHorizontMarkerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->onVerticalMarkerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_pointer_b_clicked(); break;
        case 10: _t->on_start_range_b_clicked(); break;
        case 11: _t->on_break_range_b_clicked(); break;
        case 12: _t->onMeasureModeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->onFrequencyModeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_laser_act_b_clicked(); break;
        case 15: _t->on_pulse_b_clicked(); break;
        case 16: _t->on_term_control_b_clicked(); break;
        case 17: _t->on_get_frequency_clicked(); break;
        case 18: _t->on_get_stanag_clicked(); break;
        case 19: _t->on_frequency_mode_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
