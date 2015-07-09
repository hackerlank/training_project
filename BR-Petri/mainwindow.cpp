#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->bGroup = new QButtonGroup();
    this->addButtonsToGroup();

    connect(this->ui->widget, SIGNAL(sceneClicked()),
            this, SLOT(afterClickAction()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bGroup;
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

void MainWindow::on_bt_remove_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::RemoveItem);
}

void MainWindow::addButtonsToGroup()
{
    this->bGroup->addButton(this->ui->bt_arc);
    this->bGroup->addButton(this->ui->bt_farc);
    this->bGroup->addButton(this->ui->bt_fplace);
    this->bGroup->addButton(this->ui->bt_iarc);
    this->bGroup->addButton(this->ui->bt_itrans);
    this->bGroup->addButton(this->ui->bt_normal);
    this->bGroup->addButton(this->ui->bt_place);
    this->bGroup->addButton(this->ui->bt_remove);
    this->bGroup->addButton(this->ui->bt_ttrans);
}

void MainWindow::afterClickAction()
{
    if(!this->ui->cb_lock->isChecked())
    {
        this->ui->bt_normal->click();
    }
}
