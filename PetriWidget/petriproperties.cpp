#include "petriproperties.h"
#include "view/placeview.h"
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
        this->setData();
    }
}

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    spnp::Place *place_ = ((PlaceView*)this->currentMoveable)->getPlace();
    place_->setName(arg1.toStdString());
    place_->getLabel()->setName(arg1.toStdString());
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    spnp::Place *place_ = ((PlaceView*)this->currentMoveable)->getPlace();
    place_->setToken(arg1.toDouble());
}

void PetriProperties::setData()
{
    Moveable::MoveableTypes typeOf = this->currentMoveable->getTypeName();
    switch (typeOf) {
    case Moveable::MoveableTypes::place:
        PlaceView* pv = static_cast<PlaceView*>(this->currentMoveable);
        spnp::Place* _place = pv->getPlace();
        this->ui->le_place_name->setText(QString::fromStdString(_place->getName()));
        this->ui->le_place_tokens->setText(QString::number(_place->getTokens()));
        break;
//    default:

//        break;
    }
}
