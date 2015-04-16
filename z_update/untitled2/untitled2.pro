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

unix{
    DEFINES += LINUX
}

unix:!macx: LIBS += -L$$PWD/../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/HighLighter/ -lHighlighter

INCLUDEPATH += $$PWD/../../spnp_projects/HighLighter
DEPENDPATH += $$PWD/../../spnp_projects/HighLighter

unix:!macx: LIBS += -L$$PWD/../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/SPNPClasses/ -lSPNPClasses

INCLUDEPATH += $$PWD/../../spnp_projects/SPNPClasses
DEPENDPATH += $$PWD/../../spnp_projects/SPNPClasses

unix:!macx: LIBS += -L$$PWD/../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/XMLParser/ -lXMLParser

INCLUDEPATH += $$PWD/../../spnp_projects/XMLParser
DEPENDPATH += $$PWD/../../spnp_projects/XMLParser

unix:!macx: LIBS += -L$$PWD/../../build-spnp_projects-Desktop_Qt_5_4_1_GCC_64bit-Debug/PetriWidget/ -lPetriWidget

INCLUDEPATH += $$PWD/../../spnp_projects/PetriWidget
DEPENDPATH += $$PWD/../../spnp_projects/PetriWidget

RESOURCES += \
    icons.qrc
