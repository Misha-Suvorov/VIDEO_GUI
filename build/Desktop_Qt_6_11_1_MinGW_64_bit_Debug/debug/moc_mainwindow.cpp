/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11VideoThreadE_t {};
} // unnamed namespace

template <> constexpr inline auto VideoThread::qt_create_metaobjectdata<qt_meta_tag_ZN11VideoThreadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VideoThread",
        "frameReady",
        "",
        "QImage",
        "image",
        "horizontMarkerValueChanged",
        "value",
        "verticalMarkerValueChanged",
        "frameSizeAvailable",
        "width",
        "height",
        "VideoConfig",
        "frameProcessed",
        "frameReadyForTracking",
        "cv::Mat",
        "frame",
        "processingError",
        "errorMessage",
        "setCurrentRoi",
        "cv::Rect",
        "roi"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'frameReady'
        QtMocHelpers::SignalData<void(const QImage &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'horizontMarkerValueChanged'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'verticalMarkerValueChanged'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'frameSizeAvailable'
        QtMocHelpers::SignalData<void(int, int, VideoConfig)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 }, { 0x80000000 | 11, 2 },
        }}),
        // Signal 'frameProcessed'
        QtMocHelpers::SignalData<void(const QImage &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'frameReadyForTracking'
        QtMocHelpers::SignalData<void(const cv::Mat &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Signal 'processingError'
        QtMocHelpers::SignalData<void(const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 17 },
        }}),
        // Slot 'setCurrentRoi'
        QtMocHelpers::SlotData<void(const cv::Rect &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VideoThread, qt_meta_tag_ZN11VideoThreadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoThreadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoThreadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11VideoThreadE_t>.metaTypes,
    nullptr
} };

void VideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VideoThread *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->frameReady((*reinterpret_cast<std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->horizontMarkerValueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->verticalMarkerValueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->frameSizeAvailable((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<VideoConfig>>(_a[3]))); break;
        case 4: _t->frameProcessed((*reinterpret_cast<std::add_pointer_t<QImage>>(_a[1]))); break;
        case 5: _t->frameReadyForTracking((*reinterpret_cast<std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 6: _t->processingError((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setCurrentRoi((*reinterpret_cast<std::add_pointer_t<cv::Rect>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(const QImage & )>(_a, &VideoThread::frameReady, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(int )>(_a, &VideoThread::horizontMarkerValueChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(int )>(_a, &VideoThread::verticalMarkerValueChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(int , int , VideoConfig )>(_a, &VideoThread::frameSizeAvailable, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(const QImage & )>(_a, &VideoThread::frameProcessed, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(const cv::Mat & )>(_a, &VideoThread::frameReadyForTracking, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VideoThread::*)(const QString & )>(_a, &VideoThread::processingError, 6))
            return;
    }
}

const QMetaObject *VideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoThreadE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void VideoThread::frameReady(const QImage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void VideoThread::horizontMarkerValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VideoThread::verticalMarkerValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VideoThread::frameSizeAvailable(int _t1, int _t2, VideoConfig _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3);
}

// SIGNAL 4
void VideoThread::frameProcessed(const QImage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void VideoThread::frameReadyForTracking(const cv::Mat & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void VideoThread::processingError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "displayFrame1",
        "",
        "QImage",
        "image",
        "displayFrame2",
        "onLabelClicked",
        "QPoint",
        "pos",
        "on_l_vid_turn_clicked",
        "on_switch_vid_clicked",
        "on_start_b_clicked",
        "on_stop_b_2_clicked",
        "onHorizontMarkerChanged",
        "onVerticalMarkerChanged",
        "showSpeed",
        "showDacValues",
        "vH",
        "vV",
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
        "on_mode_input_currentIndexChanged",
        "on_step_input_currentTextChanged",
        "arg1",
        "on_actionBias_calibration_triggered",
        "on_actionSet_program_0_triggered",
        "on_actionZero_set_H_triggered",
        "on_actionZero_set_V_triggered",
        "on_actionZero_reset_H_triggered",
        "on_actionZero_reset_V_triggered",
        "on_pushButton_clicked",
        "on_ext_radiation_b_clicked",
        "on_trackingButton_clicked",
        "on_btnLaserAdvanced_clicked",
        "on_stop_track_clicked",
        "on_btnLaserAdvanced_triggered",
        "QAction*"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'displayFrame1'
        QtMocHelpers::SlotData<void(const QImage &)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'displayFrame2'
        QtMocHelpers::SlotData<void(const QImage &)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'onLabelClicked'
        QtMocHelpers::SlotData<void(QPoint)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'on_l_vid_turn_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_switch_vid_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_start_b_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_stop_b_2_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onHorizontMarkerChanged'
        QtMocHelpers::SlotData<void(const float)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 2 },
        }}),
        // Slot 'onVerticalMarkerChanged'
        QtMocHelpers::SlotData<void(const float)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 2 },
        }}),
        // Slot 'showSpeed'
        QtMocHelpers::SlotData<void(const float, const float)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 2 }, { QMetaType::Float, 2 },
        }}),
        // Slot 'showDacValues'
        QtMocHelpers::SlotData<void(const float, const float)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 17 }, { QMetaType::Float, 18 },
        }}),
        // Slot 'on_pointer_b_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_start_range_b_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_break_range_b_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onMeasureModeChanged'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'onFrequencyModeChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'on_laser_act_b_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pulse_b_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_term_control_b_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_get_frequency_clicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_get_stanag_clicked'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_1_clicked'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_2_clicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_0_clicked'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_3_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_4_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_energy_5_clicked'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_mode_input_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'on_step_input_currentTextChanged'
        QtMocHelpers::SlotData<void(const QString &)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 38 },
        }}),
        // Slot 'on_actionBias_calibration_triggered'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSet_program_0_triggered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionZero_set_H_triggered'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionZero_set_V_triggered'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionZero_reset_H_triggered'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionZero_reset_V_triggered'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ext_radiation_b_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_trackingButton_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnLaserAdvanced_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_stop_track_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnLaserAdvanced_triggered'
        QtMocHelpers::SlotData<void(QAction *)>(50, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 51, 38 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->displayFrame1((*reinterpret_cast<std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->displayFrame2((*reinterpret_cast<std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->onLabelClicked((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->on_l_vid_turn_clicked(); break;
        case 4: _t->on_switch_vid_clicked(); break;
        case 5: _t->on_start_b_clicked(); break;
        case 6: _t->on_stop_b_2_clicked(); break;
        case 7: _t->onHorizontMarkerChanged((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 8: _t->onVerticalMarkerChanged((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 9: _t->showSpeed((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 10: _t->showDacValues((*reinterpret_cast<std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 11: _t->on_pointer_b_clicked(); break;
        case 12: _t->on_start_range_b_clicked(); break;
        case 13: _t->on_break_range_b_clicked(); break;
        case 14: _t->onMeasureModeChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->onFrequencyModeChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
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
        case 27: _t->on_mode_input_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_step_input_currentTextChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
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
        case 40: _t->on_btnLaserAdvanced_triggered((*reinterpret_cast<std::add_pointer_t<QAction*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
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
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
