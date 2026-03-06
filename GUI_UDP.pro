QT       += core gui widgets
QT += serialbus widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#FOR RELEASE - COMMENT
#CONFIG += debug
#

#FOR RELEASE
#INCLUDEPATH += C:\opencv_gst_release\build\install\include
#DEPENDPATH += C:\opencv_gst_release\build\install\include
#LIBS += C:\opencv_gst_release\build\install\x64\vc17\lib\opencv_world4100.lib
#FOR RELEASE END


# FOR DEBUG
INCLUDEPATH += C:\opencv_gst_debug\install\include
DEPENDPATH += C:\opencv_gst_debug\install\include
LIBS += C:\opencv_gst_debug\install\x64\vc17\lib\opencv_world4100d.lib
# FOR DEBUG END


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
    trackingworker.cpp \
    videosettings.cpp

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
    trackingworker.h \
    videosettings.h

FORMS += \
    biascalibration.ui \
    mainwindow.ui

RC_FILE = file.rc
# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Copy config.ini next to exe (Qt creates debug/release subfolders)
CONFIG_INI = $$shell_path($$PWD/config.ini)

win32 {
    contains(CONFIG, debug) {
        TARGET_INI = $$shell_path($$OUT_PWD/debug/config.ini)
    } else {
        TARGET_INI = $$shell_path($$OUT_PWD/release/config.ini)
    }
    QMAKE_POST_LINK += $$quote(cmd /c copy /Y "$$CONFIG_INI" "$$TARGET_INI")
}
