#include "petridesign.h"
#include "ui_petridesign.h"

PetriDesign::PetriDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriDesign)
{
    ui->setupUi(this);

    this->bGroup = new QButtonGroup();
    this->addButtonsToGroup();

    connect(this->ui->widget, SIGNAL(sceneClicked()),
            this, SLOT(afterClickAction()));
    connect(this->ui->widget, SIGNAL(itemSelected(QGraphicsItem*)),
            this, SLOT(afterSelectionAction(QGraphicsItem*)));
}

PetriDesign::~PetriDesign()
{
    delete ui;
    delete bGroup;
}

bool PetriDesign::isLocked()
{
    return this->ui->cb_lock->isChecked();
}

void PetriDesign::setLocked(bool l)
{
    this->ui->cb_lock->setChecked(l);
}

void PetriDesign::on_bt_normal_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::MoveItem);
}

void PetriDesign::on_bt_place_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::Place);
}

void PetriDesign::on_bt_fplace_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::FPlace);
}

void PetriDesign::on_bt_ttrans_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::TTrans);
}

void PetriDesign::on_bt_itrans_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsItem);
    this->ui->widget->getScene()->setItemType(IPetriItem::ITrans);
}

void PetriDesign::on_bt_remove_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::RemoveItem);
}

void PetriDesign::on_bt_arc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::Activator);
}

void PetriDesign::on_bt_iarc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::Inhibitor);
}

void PetriDesign::on_bt_farc_clicked()
{
    this->ui->widget->getScene()->setMode(PetriScene::InsArc);
    this->ui->widget->getScene()->setArcType(IPetriArc::FActivator);
}

void PetriDesign::afterClickAction()
{
    if(!this->ui->cb_lock->isChecked())
    {
        this->ui->bt_normal->click();
    }
}

void PetriDesign::afterSelectionAction(QGraphicsItem* item)
{
    emit this->itemSelected(item);
}

void PetriDesign::addButtonsToGroup()
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
