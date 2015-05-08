#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T18:18:36
#
#-------------------------------------------------

QT       += widgets

QT       -= gui
CONFIG	+= c++14

TARGET = PetriWidget
TEMPLATE = lib

DEFINES += PETRIWIDGET_LIBRARY

SOURCES += petriwidget.cpp \
    view/moveable.cpp \
    view/placeview.cpp \
    petributtons.cpp \
    petrieditor.cpp \
    view/immediatetransitionview.cpp

HEADERS += \
    petriwidget.h\
    petriwidget_global.h \
    view/moveable.h \
    view/placeview.h \
    petributtons.h \
    petrieditor.h \
    states.h \
    view/immediatetransitionview.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES += LINUX
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
    LIBS += -L$$OUT_PWD/../SPNPClasses/ -lSPNPClasses
}

win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SPNPClasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SPNPClasses/debug/ -lSPNPClasses
}

INCLUDEPATH += $$PWD/../SPNPClasses
DEPENDPATH += $$PWD/../SPNPClasses

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

RESOURCES += \
    imgs.qrc

FORMS += \
    petributtons.ui \
    petrieditor.ui
