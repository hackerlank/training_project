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
    view/placeview.cpp \
    petributtons.cpp \
    petrieditor.cpp \
    view/immediatetransitionview.cpp \
    petriproperties.cpp \
    view/labelview.cpp \
    view/abstractmoveable.cpp \
    view/abstractlabeledmoveable.cpp \
    petriscene.cpp \
    view/arcview.cpp

HEADERS += \
    petriwidget.h\
    petriwidget_global.h \
    view/placeview.h \
    petributtons.h \
    petrieditor.h \
    states.h \
    view/immediatetransitionview.h \
    petriproperties.h \
    view/labelview.h \
    view/abstractmoveable.h \
    view/abstractlabeledmoveable.h \
    petriscene.h \
    view/arcview.h

unix {
    target.path = /usr/lib
    INSTALLS += target
    DEFINES += LINUX
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
    LIBS += -L$$OUT_PWD/../spnpclasses/ -lSPNPClasses
}

win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/debug/ -lSPNPClasses
}

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

RESOURCES += \
    imgs.qrc

FORMS += \
    petributtons.ui \
    petrieditor.ui \
    petriproperties.ui
