#-------------------------------------------------
#
# Project created by QtCreator 2016-02-21T12:54:24
#
#-------------------------------------------------

QT      -= core gui
CONFIG  -= qt
CONFIG  += c++14
TARGET = SPNPWrapper
TEMPLATE = lib

DEFINES += SPNPWRAPPER_LIBRARY

SOURCES += spnpwrapper.cpp

HEADERS += spnpwrapper.h\
        spnpwrapper_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES +=LINUX
}

win32{
    DEFINES+=WINDOWS
}
