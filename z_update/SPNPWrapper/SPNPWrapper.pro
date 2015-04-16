#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T17:50:21
#
#-------------------------------------------------

QT      -= core gui
CONFIG	-= qt

CONFIG	+= c++14

TARGET	= SPNPWrapper
TEMPLATE= lib

DEFINES += SPNPWRAPPER_LIBRARY

SOURCES += spnpwrapper.cpp

HEADERS += spnpwrapper.h\
        spnpwrapper_global.h

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
