QT       += core gui widgets
QT += serialbus widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# OpenCV configuration
INCLUDEPATH += /Users/mac/Downloads/opencv-4.10.0/build/install/include/opencv4
LIBS += -L/Users/mac/Downloads/opencv-4.10.0/build/install/lib \
        -lopencv_world

# FFplay configuration
unix {
    # Add Homebrew binary path to the PATH environment variable
    QMAKE_PATH = /opt/homebrew/bin
    QMAKE_ENV_PATH = $$system("echo $$PATH")
    QMAKE_ENV_PATH = $$QMAKE_ENV_PATH:/opt/homebrew/bin
    QMAKE_ENV_PATH = $$unique(QMAKE_ENV_PATH)
    PATH = $$QMAKE_ENV_PATH

    # Define a macro for FFplay path
    DEFINES += FFMPEG_PATH="\\\"/opt/homebrew/bin/ffplay\\\""
}

SOURCES += \
    base.cpp \
    basecanmessage.cpp \
    canbus.cpp \
    canmessagegeneric.cpp \
    cannelloniframe.cpp \
    canthread.cpp \
    clickable.cpp \
    drawsymbols.cpp \
    lpsparameters.cpp \
    main.cpp \
    mainwindow.cpp \
    scalehorizontal.cpp \
    scalevertical.cpp \
    scalingfactor.cpp \
    senddataframe.cpp

HEADERS += \
    base.h \
    basecanmessage.h \
    canbus.h \
    canmessagegeneric.h \
    cannelloniframe.h \
    canthread.h \
    clickable.h \
    drawsymbols.h \
    lpsparameters.h \
    mainwindow.h \
    scalehorizontal.h \
    scalevertical.h \
    scalingfactor.h \
    senddataframe.h \
    structs.h

FORMS += \
    mainwindow.ui

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
