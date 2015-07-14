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

SOURCES += \
    petriproperties.cpp \
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
    diagram/petriview.cpp \
    petridesign.cpp \
    petrieditor.cpp

HEADERS += \
    petriwidget_global.h \
    petriproperties.h \
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
    diagram/petriview.h \
    petridesign.h \
    petrieditor.h

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
    petriproperties.ui \
    petridesign.ui \
    petrieditor.ui
