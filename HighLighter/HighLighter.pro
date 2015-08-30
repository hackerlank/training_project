#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T17:15:08
#
#-------------------------------------------------

QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14

TARGET = Highlighter
TEMPLATE = lib

DEFINES += HIGHLIGHTER_LIBRARY

SOURCES += highlighter.cpp

HEADERS += highlighter.h\
	highlighter_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES += LINUX
}

win32{
    DEFINES += WINDOWS
}
