QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network concurrent

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Add GStreamer paths (make sure you adjust to your local installation)
INCLUDEPATH += D:/gstreamer/1.0/mingw_x86_64/include \
               D:/gstreamer/1.0/mingw_x86_64/include/gstreamer-1.0 \
               D:/gstreamer/1.0/mingw_x86_64/include/glib-2.0 \
               D:/gstreamer/1.0/mingw_x86_64/lib/glib-2.0/include

LIBS += -LD:/gstreamer/1.0/mingw_x86_64/lib \
        -lgstreamer-1.0 \
        -lgobject-2.0 \
        -lglib-2.0 \
        -lintl\
        -lgstvideo-1.0

SOURCES += \
    devmode.cpp \
    main.cpp \
    mainwindow.cpp \
    networkdatareader.cpp \
    radardataprocessor.cpp \
    radarvisual.cpp \
    settingsmanager.cpp \
    stream.cpp \
    streammanager.cpp

HEADERS += \
    devmode.h \
    entity.h \
    mainwindow.h \
    networkdatareader.h \
    radardataprocessor.h \
    radarvisual.h \
    settingsmanager.h \
    stream.h \
    streammanager.h

FORMS += \
    devmode.ui \
    mainwindow.ui \
    stream.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE = app_icon.rc

RESOURCES += \
    Resources.qrc
