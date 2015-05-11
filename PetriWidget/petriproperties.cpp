#include "petriproperties.h"
#include "ui_petriproperties.h"

PetriProperties::PetriProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriProperties)
{
    ui->setupUi(this);
    this->currentMoveable = nullptr;
}

PetriProperties::~PetriProperties()
{
    delete ui;
}

void PetriProperties::setMoveable(Moveable *m)
{
    if(this->currentMoveable != nullptr)
    {
        this->currentMoveable->setSelected(false);
        this->currentMoveable->update();
    }

    if(m == nullptr)
    {
        this->ui->stackedWidget->setCurrentIndex(7);
    }
    else
    {
        this->currentMoveable = m;
        Moveable::MoveableTypes typeOf = this->currentMoveable->getTypeName();
        this->ui->stackedWidget->setCurrentIndex((int)typeOf);
        this->currentMoveable->setSelected(true);
    }
}
