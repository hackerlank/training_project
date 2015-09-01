#include "mainwindow.h"
#include <QApplication>

#include "appsettings.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setOrganizationName("IAS");
    app.setApplicationName("SPNP New Gui");

    MainWindow w;
    w.show();

    int executable = app.exec();

    AppSettings::Instance()->setGeometry(w.saveGeometry());
    AppSettings::Instance()->setState(w.saveState(AppSettings::VERSION));
    AppSettings::Instance()->setLocked(w.isLocked());

    return executable;
}
