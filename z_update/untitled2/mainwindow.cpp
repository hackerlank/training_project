#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "objs/net.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    highlighter = new Highlighter(this->ui->textEdit->document());
    //testando
    spnp::Net* n = new spnp::Net();
    delete n;

    //botões
    group = new QButtonGroup(this->ui->groupBox);
    group->addButton(this->ui->pb_arc);
    group->addButton(this->ui->pb_arrow);
    group->addButton(this->ui->pb_fplace);
    group->addButton(this->ui->pb_place);
    group->addButton(this->ui->pb_inhibitor);
    group->addButton(this->ui->pb_immediate);
    group->addButton(this->ui->pb_timed);
}

MainWindow::~MainWindow()
{
    delete ui;
}
