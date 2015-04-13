#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T08:28:03
#
#-------------------------------------------------

QT      -= core gui
CONFIG	-= qt

CONFIG	+= c++14

TARGET = SPNPdb
TEMPLATE = lib

DEFINES += SPNPDB_LIBRARY

SOURCES += \
    xmlnode.cpp

HEADERS +=\
        spnpdb_global.h \
    xmlnode.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32{
    DEFINES+=WINDOWS
}
unix{
    DEFINES+=LINUX
}
