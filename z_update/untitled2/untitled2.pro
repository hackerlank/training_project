#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T11:20:03
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc

unix{
    DEFINES += LINUX
    LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/HighLighter/ -lHighlighter
    LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/SPNPClasses/ -lSPNPClasses
    LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/XMLParser/ -lXMLParser
    LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/PetriWidget/ -lPetriWidget
}

win32{
    DEFINES += WINDOWS
    CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Release/HighLighter/release/ -lHighlighter
    else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Debug/HighLighter/debug/ -lHighlighter

    CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Release/SPNPClasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Debug/SPNPClasses/debug/ -lSPNPClasses

    CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Release/XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Debug/XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Release/PetriWidget/release/ -lPetriWidget
    else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-spnp_projects-Desktop_Qt_5_4_1_MinGW_32bit-Debug/PetriWidget/debug/ -lPetriWidget
}

INCLUDEPATH += $$PWD/../../HighLighter
DEPENDPATH += $$PWD/../../HighLighter

INCLUDEPATH += $$PWD/../../SPNPClasses
DEPENDPATH += $$PWD/../../SPNPClasses

INCLUDEPATH += $$PWD/../../XMLParser
DEPENDPATH += $$PWD/../../XMLParser

INCLUDEPATH += $$PWD/../../PetriWidget
DEPENDPATH += $$PWD/../../PetriWidget
