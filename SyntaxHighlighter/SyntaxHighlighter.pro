#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T14:39:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SyntaxHighlighter
TEMPLATE = app


SOURCES = highlighter.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS  += highlighter.h \
    mainwindow.h \


# install
#target.path = $$[QT_INSTALL_EXAMPLES]/richtext/syntaxhighlighter
#sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS syntaxhighlighter.pro examples
#sources.path = $$[QT_INSTALL_EXAMPLES]/richtext/syntaxhighlighter
#INSTALLS += target sources
