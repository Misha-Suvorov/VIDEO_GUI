/****************************************************************************
** Meta object code from reading C++ file 'trackingworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../trackingworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackingworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackingWorker_t {
    uint offsetsAndSizes[26];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TrackingWorker_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TrackingWorker_t qt_meta_stringdata_TrackingWorker = {
    {
        QT_MOC_LITERAL(0, 14),  // "TrackingWorker"
        QT_MOC_LITERAL(15, 16),  // "anglesCalculated"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 6),  // "angleX"
        QT_MOC_LITERAL(40, 6),  // "angleY"
        QT_MOC_LITERAL(47, 10),  // "roiUpdated"
        QT_MOC_LITERAL(58, 8),  // "cv::Rect"
        QT_MOC_LITERAL(67, 3),  // "roi"
        QT_MOC_LITERAL(71, 12),  // "processFrame"
        QT_MOC_LITERAL(84, 7),  // "cv::Mat"
        QT_MOC_LITERAL(92, 5),  // "frame"
        QT_MOC_LITERAL(98, 14),  // "setTrackingROI"
        QT_MOC_LITERAL(113, 14)   // "stopProcessing"
    },
    "TrackingWorker\0anglesCalculated\0\0"
    "angleX\0angleY\0roiUpdated\0cv::Rect\0roi\0"
    "processFrame\0cv::Mat\0frame\0setTrackingROI\0"
    "stopProcessing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackingWorker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    1,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   52,    2, 0x0a,    6 /* Public */,
      11,    1,   55,    2, 0x0a,    8 /* Public */,
      12,    0,   58,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void TrackingWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackingWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->anglesCalculated((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 1: _t->roiUpdated((*reinterpret_cast< std::add_pointer_t<cv::Rect>>(_a[1]))); break;
        case 2: _t->processFrame((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 3: _t->setTrackingROI((*reinterpret_cast< std::add_pointer_t<cv::Rect>>(_a[1]))); break;
        case 4: _t->stopProcessing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrackingWorker::*)(float , float );
            if (_t _q_method = &TrackingWorker::anglesCalculated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrackingWorker::*)(const cv::Rect & );
            if (_t _q_method = &TrackingWorker::roiUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TrackingWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TrackingWorker.offsetsAndSizes,
    qt_meta_data_TrackingWorker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrackingWorker_t
, QtPrivate::TypeAndForceComplete<TrackingWorker, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const cv::Rect &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const cv::Mat &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const cv::Rect &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrackingWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackingWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrackingWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TrackingWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TrackingWorker::anglesCalculated(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrackingWorker::roiUpdated(const cv::Rect & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
