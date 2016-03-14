#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T16:12:26
#
# https://forum.qt.io/topic/60408/accordion-widget-for-qt5/2
# https://github.com/crapp/qaccordion
#
#-------------------------------------------------

QT  -= gui
QT  += widgets

TARGET = QAccordion
TEMPLATE = lib
CONFIG += c++14

DEFINES += QACCORDION_LIBRARY

SOURCES += qaccordion.cpp \
    clickableframe.cpp \
    contentpane.cpp

HEADERS += qaccordion.h\
        qaccordion_global.h \
    clickableframe.h \
    contentpane.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES +=LINUX
}

win32{
    DEFINES += WINDOWS
}

RESOURCES += \
    icons/qaccordionicons.qrc

DISTFILES +=
