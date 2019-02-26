#-------------------------------------------------
#
# Project created by QtCreator 2019-02-13T10:25:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AndroidAuto
TEMPLATE = app


SOURCES += main.cpp\
        ui/mainwindow.cpp \
    ui/settingswindow.cpp \
    ui/connectwindow.cpp \
    ui/wirelessconnection.cpp \
    ui/musicwindow.cpp \
    system/network.cpp \
    ui/songlistwindow.cpp \
    system/clientworker.cpp \
    ui/musicsettingswindow.cpp

HEADERS  += include/mainwindow.h \
    include/settingswindow.h \
    include/connectwindow.h \
    include/wirelessconnection.h \
    include/musicwindow.h \
    include/system/network.h \
    include/system/network.hpp \
    include/songlistwindow.h \
    include/system/clientworker.h \
    include/musicsettingswindow.h

FORMS    += ui/mainwindow.ui \
    ui/settingswindow.ui \
    ui/connectwindow.ui \
    ui/wirelessconnection.ui \
    ui/musicwindow.ui \
    ui/songlistwindow.ui \
    ui/musicsettingswindow.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc

LIBS += -LC:/usr/include/jsoncpp \
        -ljsoncpp

QMAKE_CXXFLAGS += -ljsoncpp
