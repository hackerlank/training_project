#include "mainwindow.h"
#include <QApplication>

#include "appsettings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    int r = a.exec();

    AppSettings::Instance()->setGeometry(w.saveGeometry());
    AppSettings::Instance()->setState(w.saveState(AppSettings::VERSION));
    AppSettings::Instance()->setLocked(w.isLocked());

    return r;
}
