#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //TODO : refazer esse menu
    this->itemMenu = menuBar()->addMenu(tr("oi"));

    //this->scene = new PetriScene(itemMenu, this);
    //this->ui->graphicsView->setScene(this->scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_normal_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::MoveItem);
}

void MainWindow::on_bt_place_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::Place);
}

void MainWindow::on_bt_fplace_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::FPlace);
}

void MainWindow::on_bt_ttrans_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::TTrans);
}

void MainWindow::on_bt_itrans_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::ITrans);
}

void MainWindow::on_bt_arc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::Activator);
}

void MainWindow::on_bt_iarc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::Inhibitor);
}

void MainWindow::on_bt_farc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::FActivator);
}
