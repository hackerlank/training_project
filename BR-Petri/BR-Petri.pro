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
    diagram/arcs/abstractpetriarc.cpp \
    diagram/arcs/activatorarcitem.cpp \
    diagram/arcs/factivatorarcitem.cpp \
    diagram/arcs/inhibitorarcitem.cpp \
    diagram/items/abstractpetriitem.cpp \
    diagram/items/abstractpetrilabelitem.cpp \
    diagram/items/fplaceitem.cpp \
    diagram/items/imtransitem.cpp \
    diagram/items/petrilabelitem.cpp \
    diagram/items/petritextitem.cpp \
    diagram/items/placeitem.cpp \
    diagram/items/ttransitem.cpp \
    diagram/petriscene.cpp \
    diagram/petriview.cpp

HEADERS  += mainwindow.h \
    diagram/arcs/abstractpetriarc.h \
    diagram/arcs/activatorarcitem.h \
    diagram/arcs/factivatorarcitem.h \
    diagram/arcs/inhibitorarcitem.h \
    diagram/arcs/ipetriarc.h \
    diagram/items/abstractpetriitem.h \
    diagram/items/abstractpetrilabelitem.h \
    diagram/items/fplaceitem.h \
    diagram/items/imtransitem.h \
    diagram/items/ipetriitem.h \
    diagram/items/ipetrilabelitem.h \
    diagram/items/petrilabelitem.h \
    diagram/items/petritextitem.h \
    diagram/items/placeitem.h \
    diagram/items/ttransitem.h \
    diagram/petriscene.h \
    diagram/petriview.h

FORMS    += mainwindow.ui
