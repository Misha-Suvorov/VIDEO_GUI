/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoThread_t {
    uint offsetsAndSizes[40];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_VideoThread_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_VideoThread_t qt_meta_stringdata_VideoThread = {
    {
        QT_MOC_LITERAL(0, 11),  // "VideoThread"
        QT_MOC_LITERAL(12, 10),  // "frameReady"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5),  // "image"
        QT_MOC_LITERAL(30, 26),  // "horizontMarkerValueChanged"
        QT_MOC_LITERAL(57, 5),  // "value"
        QT_MOC_LITERAL(63, 26),  // "verticalMarkerValueChanged"
        QT_MOC_LITERAL(90, 18),  // "frameSizeAvailable"
        QT_MOC_LITERAL(109, 5),  // "width"
        QT_MOC_LITERAL(115, 6),  // "height"
        QT_MOC_LITERAL(122, 11),  // "VideoConfig"
        QT_MOC_LITERAL(134, 14),  // "frameProcessed"
        QT_MOC_LITERAL(149, 21),  // "frameReadyForTracking"
        QT_MOC_LITERAL(171, 7),  // "cv::Mat"
        QT_MOC_LITERAL(179, 5),  // "frame"
        QT_MOC_LITERAL(185, 15),  // "processingError"
        QT_MOC_LITERAL(201, 12),  // "errorMessage"
        QT_MOC_LITERAL(214, 13),  // "setCurrentRoi"
        QT_MOC_LITERAL(228, 8),  // "cv::Rect"
        QT_MOC_LITERAL(237, 3)   // "roi"
    },
    "VideoThread\0frameReady\0\0image\0"
    "horizontMarkerValueChanged\0value\0"
    "verticalMarkerValueChanged\0"
    "frameSizeAvailable\0width\0height\0"
    "VideoConfig\0frameProcessed\0"
    "frameReadyForTracking\0cv::Mat\0frame\0"
    "processingError\0errorMessage\0setCurrentRoi\0"
    "cv::Rect\0roi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoThread[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,
       7,    3,   71,    2, 0x06,    7 /* Public */,
      11,    1,   78,    2, 0x06,   11 /* Public */,
      12,    1,   81,    2, 0x06,   13 /* Public */,
      15,    1,   84,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,   87,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 10,    8,    9,    2,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,   16,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->frameReady((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->horizontMarkerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->verticalMarkerValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->frameSizeAvailable((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<VideoConfig>>(_a[3]))); break;
        case 4: _t->frameProcessed((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 5: _t->frameReadyForTracking((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 6: _t->processingError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setCurrentRoi((*reinterpret_cast< std::add_pointer_t<cv::Rect>>(_a[1]))); break;
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
        {
            using _t = void (VideoThread::*)(int , int , VideoConfig );
            if (_t _q_method = &VideoThread::frameSizeAvailable; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(const QImage & );
            if (_t _q_method = &VideoThread::frameProcessed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(const cv::Mat & );
            if (_t _q_method = &VideoThread::frameReadyForTracking; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VideoThread::*)(const QString & );
            if (_t _q_method = &VideoThread::processingError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject VideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_VideoThread.offsetsAndSizes,
    qt_meta_data_VideoThread,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_VideoThread_t
, QtPrivate::TypeAndForceComplete<VideoThread, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<VideoConfig, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const cv::Mat &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const cv::Rect &, std::false_type>


>,
    nullptr
} };


const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int VideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
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

// SIGNAL 3
void VideoThread::frameSizeAvailable(int _t1, int _t2, VideoConfig _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VideoThread::frameProcessed(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VideoThread::frameReadyForTracking(const cv::Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VideoThread::processingError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[100];
    char stringdata0[1011];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
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
        QT_MOC_LITERAL(172, 23),  // "onVerticalMarkerChanged"
        QT_MOC_LITERAL(196, 9),  // "showSpeed"
        QT_MOC_LITERAL(206, 13),  // "showDacValues"
        QT_MOC_LITERAL(220, 2),  // "vH"
        QT_MOC_LITERAL(223, 2),  // "vV"
        QT_MOC_LITERAL(226, 20),  // "on_pointer_b_clicked"
        QT_MOC_LITERAL(247, 24),  // "on_start_range_b_clicked"
        QT_MOC_LITERAL(272, 24),  // "on_break_range_b_clicked"
        QT_MOC_LITERAL(297, 20),  // "onMeasureModeChanged"
        QT_MOC_LITERAL(318, 5),  // "index"
        QT_MOC_LITERAL(324, 22),  // "onFrequencyModeChanged"
        QT_MOC_LITERAL(347, 22),  // "on_laser_act_b_clicked"
        QT_MOC_LITERAL(370, 18),  // "on_pulse_b_clicked"
        QT_MOC_LITERAL(389, 25),  // "on_term_control_b_clicked"
        QT_MOC_LITERAL(415, 24),  // "on_get_frequency_clicked"
        QT_MOC_LITERAL(440, 21),  // "on_get_stanag_clicked"
        QT_MOC_LITERAL(462, 19),  // "on_energy_1_clicked"
        QT_MOC_LITERAL(482, 19),  // "on_energy_2_clicked"
        QT_MOC_LITERAL(502, 19),  // "on_energy_0_clicked"
        QT_MOC_LITERAL(522, 19),  // "on_energy_3_clicked"
        QT_MOC_LITERAL(542, 19),  // "on_energy_4_clicked"
        QT_MOC_LITERAL(562, 19),  // "on_energy_5_clicked"
        QT_MOC_LITERAL(582, 33),  // "on_mode_input_currentIndexCha..."
        QT_MOC_LITERAL(616, 32),  // "on_step_input_currentTextChanged"
        QT_MOC_LITERAL(649, 4),  // "arg1"
        QT_MOC_LITERAL(654, 35),  // "on_actionBias_calibration_tri..."
        QT_MOC_LITERAL(690, 32),  // "on_actionSet_program_0_triggered"
        QT_MOC_LITERAL(723, 29),  // "on_actionZero_set_H_triggered"
        QT_MOC_LITERAL(753, 29),  // "on_actionZero_set_V_triggered"
        QT_MOC_LITERAL(783, 31),  // "on_actionZero_reset_H_triggered"
        QT_MOC_LITERAL(815, 31),  // "on_actionZero_reset_V_triggered"
        QT_MOC_LITERAL(847, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(869, 26),  // "on_ext_radiation_b_clicked"
        QT_MOC_LITERAL(896, 25),  // "on_trackingButton_clicked"
        QT_MOC_LITERAL(922, 27),  // "on_btnLaserAdvanced_clicked"
        QT_MOC_LITERAL(950, 21),  // "on_stop_track_clicked"
        QT_MOC_LITERAL(972, 29),  // "on_btnLaserAdvanced_triggered"
        QT_MOC_LITERAL(1002, 8)   // "QAction*"
    },
    "MainWindow\0displayFrame1\0\0image\0"
    "displayFrame2\0onLabelClicked\0pos\0"
    "on_l_vid_turn_clicked\0on_switch_vid_clicked\0"
    "on_start_b_clicked\0on_stop_b_2_clicked\0"
    "onHorizontMarkerChanged\0onVerticalMarkerChanged\0"
    "showSpeed\0showDacValues\0vH\0vV\0"
    "on_pointer_b_clicked\0on_start_range_b_clicked\0"
    "on_break_range_b_clicked\0onMeasureModeChanged\0"
    "index\0onFrequencyModeChanged\0"
    "on_laser_act_b_clicked\0on_pulse_b_clicked\0"
    "on_term_control_b_clicked\0"
    "on_get_frequency_clicked\0on_get_stanag_clicked\0"
    "on_energy_1_clicked\0on_energy_2_clicked\0"
    "on_energy_0_clicked\0on_energy_3_clicked\0"
    "on_energy_4_clicked\0on_energy_5_clicked\0"
    "on_mode_input_currentIndexChanged\0"
    "on_step_input_currentTextChanged\0arg1\0"
    "on_actionBias_calibration_triggered\0"
    "on_actionSet_program_0_triggered\0"
    "on_actionZero_set_H_triggered\0"
    "on_actionZero_set_V_triggered\0"
    "on_actionZero_reset_H_triggered\0"
    "on_actionZero_reset_V_triggered\0"
    "on_pushButton_clicked\0on_ext_radiation_b_clicked\0"
    "on_trackingButton_clicked\0"
    "on_btnLaserAdvanced_clicked\0"
    "on_stop_track_clicked\0"
    "on_btnLaserAdvanced_triggered\0QAction*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  260,    2, 0x08,    1 /* Private */,
       4,    1,  263,    2, 0x08,    3 /* Private */,
       5,    1,  266,    2, 0x08,    5 /* Private */,
       7,    0,  269,    2, 0x08,    7 /* Private */,
       8,    0,  270,    2, 0x08,    8 /* Private */,
       9,    0,  271,    2, 0x08,    9 /* Private */,
      10,    0,  272,    2, 0x08,   10 /* Private */,
      11,    1,  273,    2, 0x08,   11 /* Private */,
      12,    1,  276,    2, 0x08,   13 /* Private */,
      13,    2,  279,    2, 0x08,   15 /* Private */,
      14,    2,  284,    2, 0x08,   18 /* Private */,
      17,    0,  289,    2, 0x08,   21 /* Private */,
      18,    0,  290,    2, 0x08,   22 /* Private */,
      19,    0,  291,    2, 0x08,   23 /* Private */,
      20,    1,  292,    2, 0x08,   24 /* Private */,
      22,    1,  295,    2, 0x08,   26 /* Private */,
      23,    0,  298,    2, 0x08,   28 /* Private */,
      24,    0,  299,    2, 0x08,   29 /* Private */,
      25,    0,  300,    2, 0x08,   30 /* Private */,
      26,    0,  301,    2, 0x08,   31 /* Private */,
      27,    0,  302,    2, 0x08,   32 /* Private */,
      28,    0,  303,    2, 0x08,   33 /* Private */,
      29,    0,  304,    2, 0x08,   34 /* Private */,
      30,    0,  305,    2, 0x08,   35 /* Private */,
      31,    0,  306,    2, 0x08,   36 /* Private */,
      32,    0,  307,    2, 0x08,   37 /* Private */,
      33,    0,  308,    2, 0x08,   38 /* Private */,
      34,    1,  309,    2, 0x08,   39 /* Private */,
      35,    1,  312,    2, 0x08,   41 /* Private */,
      37,    0,  315,    2, 0x08,   43 /* Private */,
      38,    0,  316,    2, 0x08,   44 /* Private */,
      39,    0,  317,    2, 0x08,   45 /* Private */,
      40,    0,  318,    2, 0x08,   46 /* Private */,
      41,    0,  319,    2, 0x08,   47 /* Private */,
      42,    0,  320,    2, 0x08,   48 /* Private */,
      43,    0,  321,    2, 0x08,   49 /* Private */,
      44,    0,  322,    2, 0x08,   50 /* Private */,
      45,    0,  323,    2, 0x08,   51 /* Private */,
      46,    0,  324,    2, 0x08,   52 /* Private */,
      47,    0,  325,    2, 0x08,   53 /* Private */,
      48,    1,  326,    2, 0x08,   54 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
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
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::QString,   36,
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
    QMetaType::Void, 0x80000000 | 49,   36,

       0        // eod
};

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
        case 7: _t->onHorizontMarkerChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 8: _t->onVerticalMarkerChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 9: _t->showSpeed((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 10: _t->showDacValues((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 11: _t->on_pointer_b_clicked(); break;
        case 12: _t->on_start_range_b_clicked(); break;
        case 13: _t->on_break_range_b_clicked(); break;
        case 14: _t->onMeasureModeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->onFrequencyModeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_laser_act_b_clicked(); break;
        case 17: _t->on_pulse_b_clicked(); break;
        case 18: _t->on_term_control_b_clicked(); break;
        case 19: _t->on_get_frequency_clicked(); break;
        case 20: _t->on_get_stanag_clicked(); break;
        case 21: _t->on_energy_1_clicked(); break;
        case 22: _t->on_energy_2_clicked(); break;
        case 23: _t->on_energy_0_clicked(); break;
        case 24: _t->on_energy_3_clicked(); break;
        case 25: _t->on_energy_4_clicked(); break;
        case 26: _t->on_energy_5_clicked(); break;
        case 27: _t->on_mode_input_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_step_input_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->on_actionBias_calibration_triggered(); break;
        case 30: _t->on_actionSet_program_0_triggered(); break;
        case 31: _t->on_actionZero_set_H_triggered(); break;
        case 32: _t->on_actionZero_set_V_triggered(); break;
        case 33: _t->on_actionZero_reset_H_triggered(); break;
        case 34: _t->on_actionZero_reset_V_triggered(); break;
        case 35: _t->on_pushButton_clicked(); break;
        case 36: _t->on_ext_radiation_b_clicked(); break;
        case 37: _t->on_trackingButton_clicked(); break;
        case 38: _t->on_btnLaserAdvanced_clicked(); break;
        case 39: _t->on_stop_track_clicked(); break;
        case 40: _t->on_btnLaserAdvanced_triggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>


>,
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
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
