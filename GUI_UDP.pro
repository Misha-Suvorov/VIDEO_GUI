QT       += core gui widgets
QT += serialbus widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug


#INCLUDEPATH += C:\opencv_gst_complete_debug\opencv-install-debug\include
#DEPENDPATH += C:\opencv_gst_complete_debug\opencv-install-debug\include
#LIBS += C:\opencv_gst_complete_debug\opencv-install-debug\x64\vc17\lib\opencv_world4100d.lib

INCLUDEPATH += C:\opencv_gst_debug\install\include
DEPENDPATH += C:\opencv_gst_debug\install\include
LIBS += C:\opencv_gst_debug\install\x64\vc17\lib\opencv_world4100d.lib

#INCLUDEPATH += C:/opencv_gst_complete_debug/opencv-install-debug/include/opencv2

#INCLUDEPATH += C:\opencv_gst_complete_debug\opencv-4.10.0\build\install\include
#DEPENDPATH += C:\opencv_gst_complete_debug\opencv-4.10.0\build\install\include
#LIBS += C:\opencv_gst_complete_debug\opencv-4.10.0\build\install\x64\vc17\lib\opencv_world4100.lib

INCLUDEPATH += C:\Qt\6.2.13\msvc2019_64\include
DEPENDPATH += C:\Qt\6.2.13\msvc2019_64\include
INCLUDEPATH += C:\Qt\6.2.13\msvc2019_64\include\QtGui
DEPENDPATH += C:\Qt\6.2.13\msvc2019_64\include\QtGui

INCLUDEPATH += C:\Qt\6.2.13\msvc2019_64\include\QtWidgets
DEPENDPATH += C:\Qt\6.2.13\msvc2019_64\include\QtWidgets

INCLUDEPATH += C:\Qt\6.2.13\msvc2019_64\include\QtCore
DEPENDPATH += C:\Qt\6.2.13\msvc2019_64\include\QtCore

INCLUDEPATH += C:\Qt\6.2.13\msvc2019_64\include\QtNetwork
DEPENDPATH += C:\Qt\6.2.13\msvc2019_64\include\QtNetwork



SOURCES += \
    base.cpp \
    basecanmessage.cpp \
    biascalibration.cpp \
    canbus.cpp \
    canmessagegeneric.cpp \
    cannelloniframe.cpp \
    canparserworker.cpp \
    canthread.cpp \
    clickable.cpp \
    drawsymbols.cpp \
    inertMoving.cpp \
    laserparameters.cpp \
    lpsparameters.cpp \
    main.cpp \
    mainwindow.cpp \
    pixeltoangleconverter.cpp \
    scalehorizontal.cpp \
    scalevertical.cpp \
    scalingfactor.cpp \
    scriptcommands.cpp \
    senddataframe.cpp \
    tracking.cpp

HEADERS += \
    CircularBuffer.h \
    base.h \
    basecanmessage.h \
    biascalibration.h \
    canbus.h \
    canmessagegeneric.h \
    cannelloniframe.h \
    canparserworker.h \
    canthread.h \
    clickable.h \
    drawsymbols.h \
    inertMoving.h \
    laserparameters.h \
    lpsparameters.h \
    mainwindow.h \
    pixeltoangleconverter.h \
    scalehorizontal.h \
    scalevertical.h \
    scalingfactor.h \
    scriptcommands.h \
    senddataframe.h \
    structs.h \
    tracking.h

FORMS += \
    biascalibration.ui \
    mainwindow.ui

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
