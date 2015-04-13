#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T11:57:26
#
#-------------------------------------------------

QT       -= core gui
CONFIG	-= qt

CONFIG	+= c++14

TARGET = SPNPdb
TEMPLATE = lib

TARGET = spnpclasses
TEMPLATE = lib

DEFINES += SPNPCLASSES_LIBRARY

SOURCES += \
    objs/net.cpp \
    objs/place.cpp \
    objs/transition.cpp \
    objs/arc.cpp \
    abstractdata.cpp \
    abstractvisualdata.cpp \
    objs/label.cpp \
    objs/project.cpp \
    objs/timedtransition.cpp \
    objs/fluidplace.cpp \
    objs/fluidarc.cpp

HEADERS +=\
        spnpclasses_global.h \
    objs/net.h \
    objs/place.h \
    objs/transition.h \
    objs/arc.h \
    abstractdata.h \
    abstractvisualdata.h \
    idata.h \
    objs/label.h \
    objs/project.h \
    objs/timedtransition.h \
    objs/fluidplace.h \
    objs/fluidarc.h

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SPNPdb-Desktop_Qt_5_4_1_MinGW_32bit-Debug/release/ -lSPNPdb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SPNPdb-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/ -lSPNPdb

INCLUDEPATH += $$PWD/../SPNPdb
DEPENDPATH += $$PWD/../SPNPdb
