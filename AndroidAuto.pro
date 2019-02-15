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
    system/SettingsManager.cpp

HEADERS  += include/mainwindow.h \
    include/settingswindow.h \
    include/connectwindow.h \
    include/wirelessconnection.h \
    include/musicwindow.h \
    include/system/SettingsManager.h

FORMS    += ui/mainwindow.ui \
    ui/settingswindow.ui \
    ui/connectwindow.ui \
    ui/wirelessconnection.ui \
    ui/musicwindow.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc

QMAKE_CXXFLAGS += -lpthread
