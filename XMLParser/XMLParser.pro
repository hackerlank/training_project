#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T16:39:38
#
#-------------------------------------------------

QT      -= core gui
CONFIG	-= qt
CONFIG	+= c++14
TARGET = XMLParser
TEMPLATE = lib

DEFINES += XMLPARSER_LIBRARY

SOURCES += xmlparser.cpp \
    base64.cpp

HEADERS += xmlparser.h\
        xmlparser_global.h \
    base64.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES+=LINUX
}

win32{
    DEFINES+=WINDOWS
}
