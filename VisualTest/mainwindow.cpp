#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_SPNP_triggered()
{
    Ui_about about;//(0,0);
    about.setFixedSize(about.width(), about.height());
    about.exec();
    about.show();
}
