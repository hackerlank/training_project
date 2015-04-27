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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/release/ -lPetriWidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/debug/ -lPetriWidget

INCLUDEPATH += $$PWD/../PetriWidget
DEPENDPATH += $$PWD/../PetriWidget
