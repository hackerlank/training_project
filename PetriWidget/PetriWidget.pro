#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T18:18:36
#
#-------------------------------------------------

QT       += widgets

QT       -= gui
CONFIG	+= c++14

TARGET = PetriWidget
TEMPLATE = lib

DEFINES += PETRIWIDGET_LIBRARY

SOURCES += petriwidget.cpp \
    placeview.cpp

HEADERS += petriwidget.h\
        petriwidget_global.h \
    placeview.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES += LINUX
    LIBS += -L$$OUT_PWD/../SPNPClasses/ -lSPNPClasses
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
}

win32{
    DEFINES += WINDOWS
}

INCLUDEPATH += $$PWD/../SPNPClasses
DEPENDPATH += $$PWD/../SPNPClasses

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser
