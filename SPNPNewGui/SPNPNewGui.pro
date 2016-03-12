#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T16:55:53
#
#-------------------------------------------------

QT      += core gui
CONFIG	+= c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPNPNewGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    appsettings.cpp \
    newprojectdialog.cpp \
    analysissimulationdialog.cpp \
    optionsdialog.cpp \
    pathsetupform.cpp

HEADERS  += mainwindow.h \
    appsettings.h \
    newprojectdialog.h \
    analysissimulationdialog.h \
    optionsdialog.h \
    pathsetupform.h

FORMS    += mainwindow.ui \
    newprojectdialog.ui \
    analysissimulationdialog.ui \
    optionsdialog.ui \
    pathsetupform.ui

unix{
    DEFINES += LINUX
    LIBS += -L$$OUT_PWD/../HighLighter/ -lHighlighter
    LIBS += -L$$OUT_PWD/../SaveLoadFile/ -lSaveLoadFile
    LIBS += -L$$OUT_PWD/../XMLParser/ -lXMLParser
    LIBS += -L$$OUT_PWD/../spnpclasses/ -lSPNPClasses
    LIBS += -L$$OUT_PWD/../PetriWidget/ -lPetriWidget
    LIBS += -L$$OUT_PWD/../cspl/ -lcspl
    LIBS += -L$$OUT_PWD/../SPNPWrapper/ -lSPNPWrapper
}

win32{
    DEFINES += WINDOWS

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../HighLighter/release/ -lHighlighter
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../HighLighter/debug/ -lHighlighter

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SaveLoadFile/release/ -lSaveLoadFile
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SaveLoadFile/debug/ -lSaveLoadFile

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/release/ -lXMLParser
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XMLParser/debug/ -lXMLParser

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/release/ -lSPNPClasses
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../spnpclasses/debug/ -lSPNPClasses

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/release/ -lPetriWidget
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PetriWidget/debug/ -lPetriWidget

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cspl/release/ -lcspl
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cspl/debug/ -lcspl

    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SPNPWrapper/release/ -lSPNPWrapper
    else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SPNPWrapper/debug/ -lSPNPWrapper
}

INCLUDEPATH += $$PWD/../HighLighter
DEPENDPATH += $$PWD/../HighLighter

INCLUDEPATH += $$PWD/../SaveLoadFile
DEPENDPATH += $$PWD/../SaveLoadFile

INCLUDEPATH += $$PWD/../XMLParser
DEPENDPATH += $$PWD/../XMLParser

INCLUDEPATH += $$PWD/../spnpclasses
DEPENDPATH += $$PWD/../spnpclasses

INCLUDEPATH += $$PWD/../PetriWidget
DEPENDPATH += $$PWD/../PetriWidget

INCLUDEPATH += $$PWD/../cspl
DEPENDPATH += $$PWD/../cspl

INCLUDEPATH += $$PWD/../SPNPWrapper
DEPENDPATH += $$PWD/../SPNPWrapper
