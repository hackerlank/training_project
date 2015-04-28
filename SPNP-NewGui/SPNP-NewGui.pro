#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T20:31:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPNP-NewGui
TEMPLATE = app
CONFIG	+= c++14

SOURCES += main.cpp\
	mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32{
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SPNPClasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SPNPClasses/debug/ -lSPNPClasses

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/release/ -lPetriWidget
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/debug/ -lPetriWidget
}

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

INCLUDEPATH += $$PWD/../SPNPClasses
DEPENDPATH += $$PWD/../SPNPClasses

INCLUDEPATH += $$PWD/../PetriWidget
DEPENDPATH += $$PWD/../PetriWidget
