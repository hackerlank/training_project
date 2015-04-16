#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T16:48:52
#
#-------------------------------------------------

QT       -= core gui

CONFIG	-= qt
CONFIG	+= c++14

TARGET = SPNPClasses
TEMPLATE = lib

DEFINES += SPNPCLASSES_LIBRARY

SOURCES += \
    objs/arc.cpp \
    objs/fluidarc.cpp \
    objs/fluidplace.cpp \
    objs/label.cpp \
    objs/net.cpp \
    objs/place.cpp \
    objs/project.cpp \
    objs/timedtransition.cpp \
    objs/transition.cpp \
    abstractdata.cpp \
    abstractvisualdata.cpp

HEADERS +=\
        spnpclasses_global.h \
    objs/arc.h \
    objs/fluidarc.h \
    objs/fluidplace.h \
    objs/label.h \
    objs/net.h \
    objs/place.h \
    objs/project.h \
    objs/timedtransition.h \
    objs/transition.h \
    abstractdata.h \
    abstractvisualdata.h \
    idata.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES+=LINUX

    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
}

win32{
    DEFINES += WINDOWS
}

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser
