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
    "image",
    "horizontMarkerValueChanged",
    "value",
    "verticalMarkerValueChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVideoThreadENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[27];
    char stringdata5[6];
    char stringdata6[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVideoThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVideoThreadENDCLASS_t qt_meta_stringdata_CLASSVideoThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "VideoThread"
        QT_MOC_LITERAL(12, 10),  // "frameReady"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5),  // "image"
        QT_MOC_LITERAL(30, 26),  // "horizontMarkerValueChanged"
        QT_MOC_LITERAL(57, 5),  // "value"
        QT_MOC_LITERAL(63, 26)   // "verticalMarkerValueChanged"
    },
    "VideoThread",
    "frameReady",
    "",
    "image",
    "horizontMarkerValueChanged",
    "value",
    "verticalMarkerValueChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       4,    1,   35,    2, 0x06,    3 /* Public */,
       6,    1,   38,    2, 0x06,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

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
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'horizontMarkerValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'verticalMarkerValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
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
        case 1: _t->horizontMarkerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->verticalMarkerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
        {
            using _t = void (VideoThread::*)(int );
            if (_t _q_method = &VideoThread::horizontMarkerValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(int );
            if (_t _q_method = &VideoThread::verticalMarkerValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::frameReady(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoThread::horizontMarkerValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoThread::verticalMarkerValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
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
    "onLabelClicked",
    "pos",
    "on_l_vid_turn_clicked",
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
    "on_energy_1_clicked",
    "on_energy_2_clicked",
    "on_energy_0_clicked",
    "on_energy_3_clicked",
    "on_energy_4_clicked",
    "on_energy_5_clicked",
    "on_mode_input_currentIndexChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[15];
    char stringdata6[4];
    char stringdata7[22];
    char stringdata8[22];
    char stringdata9[19];
    char stringdata10[20];
    char stringdata11[24];
    char stringdata12[5];
    char stringdata13[24];
    char stringdata14[21];
    char stringdata15[25];
    char stringdata16[25];
    char stringdata17[21];
    char stringdata18[6];
    char stringdata19[23];
    char stringdata20[23];
    char stringdata21[19];
    char stringdata22[26];
    char stringdata23[25];
    char stringdata24[22];
    char stringdata25[20];
    char stringdata26[20];
    char stringdata27[20];
    char stringdata28[20];
    char stringdata29[20];
    char stringdata30[20];
    char stringdata31[34];
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
        QT_MOC_LITERAL(46, 14),  // "onLabelClicked"
        QT_MOC_LITERAL(61, 3),  // "pos"
        QT_MOC_LITERAL(65, 21),  // "on_l_vid_turn_clicked"
        QT_MOC_LITERAL(87, 21),  // "on_switch_vid_clicked"
        QT_MOC_LITERAL(109, 18),  // "on_start_b_clicked"
        QT_MOC_LITERAL(128, 19),  // "on_stop_b_2_clicked"
        QT_MOC_LITERAL(148, 23),  // "onHorizontMarkerChanged"
        QT_MOC_LITERAL(172, 4),  // "text"
        QT_MOC_LITERAL(177, 23),  // "onVerticalMarkerChanged"
        QT_MOC_LITERAL(201, 20),  // "on_pointer_b_clicked"
        QT_MOC_LITERAL(222, 24),  // "on_start_range_b_clicked"
        QT_MOC_LITERAL(247, 24),  // "on_break_range_b_clicked"
        QT_MOC_LITERAL(272, 20),  // "onMeasureModeChanged"
        QT_MOC_LITERAL(293, 5),  // "index"
        QT_MOC_LITERAL(299, 22),  // "onFrequencyModeChanged"
        QT_MOC_LITERAL(322, 22),  // "on_laser_act_b_clicked"
        QT_MOC_LITERAL(345, 18),  // "on_pulse_b_clicked"
        QT_MOC_LITERAL(364, 25),  // "on_term_control_b_clicked"
        QT_MOC_LITERAL(390, 24),  // "on_get_frequency_clicked"
        QT_MOC_LITERAL(415, 21),  // "on_get_stanag_clicked"
        QT_MOC_LITERAL(437, 19),  // "on_energy_1_clicked"
        QT_MOC_LITERAL(457, 19),  // "on_energy_2_clicked"
        QT_MOC_LITERAL(477, 19),  // "on_energy_0_clicked"
        QT_MOC_LITERAL(497, 19),  // "on_energy_3_clicked"
        QT_MOC_LITERAL(517, 19),  // "on_energy_4_clicked"
        QT_MOC_LITERAL(537, 19),  // "on_energy_5_clicked"
        QT_MOC_LITERAL(557, 33)   // "on_mode_input_currentIndexCha..."
    },
    "MainWindow",
    "displayFrame1",
    "",
    "image",
    "displayFrame2",
    "onLabelClicked",
    "pos",
    "on_l_vid_turn_clicked",
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
    "on_energy_1_clicked",
    "on_energy_2_clicked",
    "on_energy_0_clicked",
    "on_energy_3_clicked",
    "on_energy_4_clicked",
    "on_energy_5_clicked",
    "on_mode_input_currentIndexChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  170,    2, 0x08,    1 /* Private */,
       4,    1,  173,    2, 0x08,    3 /* Private */,
       5,    1,  176,    2, 0x08,    5 /* Private */,
       7,    0,  179,    2, 0x08,    7 /* Private */,
       8,    0,  180,    2, 0x08,    8 /* Private */,
       9,    0,  181,    2, 0x08,    9 /* Private */,
      10,    0,  182,    2, 0x08,   10 /* Private */,
      11,    1,  183,    2, 0x08,   11 /* Private */,
      13,    1,  186,    2, 0x08,   13 /* Private */,
      14,    0,  189,    2, 0x08,   15 /* Private */,
      15,    0,  190,    2, 0x08,   16 /* Private */,
      16,    0,  191,    2, 0x08,   17 /* Private */,
      17,    1,  192,    2, 0x08,   18 /* Private */,
      19,    1,  195,    2, 0x08,   20 /* Private */,
      20,    0,  198,    2, 0x08,   22 /* Private */,
      21,    0,  199,    2, 0x08,   23 /* Private */,
      22,    0,  200,    2, 0x08,   24 /* Private */,
      23,    0,  201,    2, 0x08,   25 /* Private */,
      24,    0,  202,    2, 0x08,   26 /* Private */,
      25,    0,  203,    2, 0x08,   27 /* Private */,
      26,    0,  204,    2, 0x08,   28 /* Private */,
      27,    0,  205,    2, 0x08,   29 /* Private */,
      28,    0,  206,    2, 0x08,   30 /* Private */,
      29,    0,  207,    2, 0x08,   31 /* Private */,
      30,    0,  208,    2, 0x08,   32 /* Private */,
      31,    1,  209,    2, 0x08,   33 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
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
    QMetaType::Void, QMetaType::Int,   18,

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
        // method 'onLabelClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'on_l_vid_turn_clicked'
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
        // method 'on_energy_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_energy_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_energy_0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_energy_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_energy_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_energy_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mode_input_currentIndexChanged'
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
        case 2: _t->onLabelClicked((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->on_l_vid_turn_clicked(); break;
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
        case 19: _t->on_energy_1_clicked(); break;
        case 20: _t->on_energy_2_clicked(); break;
        case 21: _t->on_energy_0_clicked(); break;
        case 22: _t->on_energy_3_clicked(); break;
        case 23: _t->on_energy_4_clicked(); break;
        case 24: _t->on_energy_5_clicked(); break;
        case 25: _t->on_mode_input_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
