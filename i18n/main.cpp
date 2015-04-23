#include <QApplication>

#include <QTranslator>
#include <QLibraryInfo>
#include "mainwindow.h"

#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load(
                QCoreApplication::applicationName()+"_"+QLocale::system().name(),
                QCoreApplication::applicationDirPath()+"/lang");

    app.installTranslator(&myappTranslator);

    MainWindow w;
    w.show();

    return app.exec();
}
