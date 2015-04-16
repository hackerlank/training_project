CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(petrinetplugin)
TEMPLATE    = lib
CONFIG	    += c++14

HEADERS     = netviewplugin.h petrinet.h \
    projectformplugin.h
SOURCES     = netviewplugin.cpp petrinet.cpp \
    projectformplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(netview.pri)
include(projectview.pri)

win32{
    DEFINES += WINDOWS
}

unix{
    CONFIG(release, debug|release) {
	LIBS += -L$$PWD/../build-spnpclasses-Desktop_Qt_5_4_1_GCC_64bit-Release/ -lspnpclasses
	LIBS += -L$$PWD/../build-SPNPdb-Desktop_Qt_5_4_1_GCC_64bit-Release/ -lSPNPdb
    }
    CONFIG(debug, debug|release) {
	LIBS += -L$$PWD/../build-spnpclasses-Desktop_Qt_5_4_1_GCC_64bit-Debug/ -lspnpclasses
	LIBS += -L$$PWD/../build-SPNPdb-Desktop_Qt_5_4_1_GCC_64bit-Debug/ -lSPNPdb
    }
    DEFINES += LINUX
}

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses

INCLUDEPATH += $$PWD/../SPNPdb
DEPENDPATH += $$PWD/../SPNPdb
