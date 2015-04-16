TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14
SOURCES += main.cpp

#usar gcc 2.95.2
include(deployment.pri)
qtcAddDeployment()

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SPNPWrapper-Desktop_Qt_5_4_0_MinGW_32bit-Debug/release/ -lSPNPWrapper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SPNPWrapper-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/ -lSPNPWrapper

INCLUDEPATH += $$PWD/../SPNPWrapper
DEPENDPATH += $$PWD/../SPNPWrapper
