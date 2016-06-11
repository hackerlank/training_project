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
    objs/fluidplace.cpp \
    objs/label.cpp \
    objs/net.cpp \
    objs/place.cpp \
    objs/project.cpp \
    objs/timedtransition.cpp \
    abstractdata.cpp \
    abstractvisualdata.cpp \
    objs/immediatetransition.cpp \
    objs/option.cpp \
    objs/outputoption.cpp \
    objs/parameter.cpp \
    objs/outputfunction.cpp

HEADERS +=\
	spnpclasses_global.h \
    objs/arc.h \
    objs/fluidplace.h \
    objs/label.h \
    objs/net.h \
    objs/place.h \
    objs/project.h \
    objs/timedtransition.h \
    abstractdata.h \
    abstractvisualdata.h \
    idata.h \
    objs/immediatetransition.h \
    objs/option.h \
    objs/outputoption.h \
    objs/parameter.h \
    objs/outputfunction.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES+=LINUX

    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
}

win32{
    DEFINES += WINDOWS
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser
}

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser
