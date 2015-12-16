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
}

win32{
    DEFINES += WINDOWS
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/release/ -lSPNPClasses
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/debug/ -lSPNPClasses
else:unix:!macx: LIBS += -L$$OUT_PWD/../spnpclasses/ -lSPNPClasses

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser
else:unix:!macx: LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses
