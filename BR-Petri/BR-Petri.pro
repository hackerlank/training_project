#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T15:37:26
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BR-Petri
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp \
    diagram/placeitem.cpp \
    diagram/abstractpetriitem.cpp \
    diagram/abstractpetriarc.cpp \
    diagram/petriscene.cpp \
    diagram/petritextitem.cpp \
    diagram/fplaceitem.cpp \
    diagram/ttransitem.cpp \
    diagram/itransitem.cpp

HEADERS  += mainwindow.h \
    diagram/placeitem.h \
    diagram/abstractpetriitem.h \
    diagram/abstractpetriarc.h \
    diagram/petriscene.h \
    diagram/petritextitem.h \
    diagram/ipetriitem.h \
    diagram/fplaceitem.h \
    diagram/ttransitem.h \
    diagram/itransitem.h

FORMS    += mainwindow.ui
