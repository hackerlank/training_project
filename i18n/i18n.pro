#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T14:48:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = i18n
TEMPLATE = app

DEFINES += TARGET=\\\"$${TARGET}\\\"

SOURCES += main.cpp\
        mainwindow.cpp \
    i18n.cpp

HEADERS  += mainwindow.h \
    i18n.h

FORMS    += mainwindow.ui

TRANSLATIONS += lang/$${TARGET}_pt_BR.ts \
	    lang/$${TARGET}_en_US.ts

#CODECFORSRC = UTF-8
