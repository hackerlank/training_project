#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "appsettings.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->restoreGeometry(AppSettings::Instance()->getGeometry());
    this->restoreState(AppSettings::Instance()->getState(), AppSettings::VERSION);
    this->ui->widget->setLocked(AppSettings::Instance()->isLocked());

    this->psf = new PreferenceSetupForm(this);
    this->psf->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->psf;
}

bool MainWindow::isLocked()
{
    return this->ui->widget->isLocked();
}

void MainWindow::on_action_preferencias_triggered()
{
    this->psf->show();
}
