#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T20:52:23
#
#-------------------------------------------------

QT      -= core gui

CONFIG	-= qt
CONFIG  += c++14

TARGET = cspl
TEMPLATE = lib

DEFINES += CSPL_LIBRARY

SOURCES += cspl.cpp

HEADERS += cspl.h\
        cspl_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES +=LINUX

    LIBS += -L$$OUT_PWD/../spnpclasses/ -lSPNPClasses
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
}

win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/release/ -lSPNPClasses
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/debug/ -lSPNPClasses

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser
}

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses
