#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T17:40:14
#
#-------------------------------------------------
QT      -= core gui
CONFIG	-= qt
CONFIG	+= c++14
TARGET	= SaveLoadFile
TEMPLATE= lib

DEFINES += SAVELOADFILE_LIBRARY

SOURCES += saveloadfile.cpp

HEADERS += saveloadfile.h\
        saveloadfile_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES +=LINUX
}

win32{
    DEFINES += WINDOWS
}
