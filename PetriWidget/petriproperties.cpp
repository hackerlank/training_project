#include "petriproperties.h"
#include "view/placeview.h"
#include "view/immediatetransitionview.h"
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

void PetriProperties::setMoveable(AbstractMoveable *m)
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
        AbstractMoveable::MoveableTypes typeOf = this->currentMoveable->getTypeName();
        this->ui->stackedWidget->setCurrentIndex((int)typeOf);
        this->currentMoveable->setSelected(true);
        this->setData();
    }
}

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    PlaceView* pv = static_cast<PlaceView*>(this->currentMoveable);
    pv->setName(arg1.toStdString());
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    PlaceView* pv = static_cast<PlaceView*>(this->currentMoveable);
    pv->setValue(arg1.toDouble());
}

void PetriProperties::setData()
{
    AbstractMoveable::MoveableTypes typeOf = this->currentMoveable->getTypeName();
    switch (typeOf)
    {
    case AbstractMoveable::MoveableTypes::place:
    {
        PlaceView* pv = static_cast<PlaceView*>(this->currentMoveable);
        this->ui->le_place_name->setText(QString::fromStdString(pv->getName()));
        this->ui->le_place_tokens->setText(QString::number(pv->getValue()));
        break;
    }
    case AbstractMoveable::MoveableTypes::fplace:
    case AbstractMoveable::MoveableTypes::itrans:
    {
        ImmediateTransitionView* itv = static_cast<ImmediateTransitionView*>(this->currentMoveable);
        this->ui->le_itrans_name->setText(QString::fromStdString(itv->getName()));
        break;
    }
    case AbstractMoveable::MoveableTypes::ttrans:
    case AbstractMoveable::MoveableTypes::arc:
    case AbstractMoveable::MoveableTypes::farc:
    case AbstractMoveable::MoveableTypes::inhibitor:
    case AbstractMoveable::MoveableTypes::net:
        break;
    }
}

void PetriProperties::on_le_itrans_name_textEdited(const QString &arg1)
{
    ImmediateTransitionView* itv = static_cast<ImmediateTransitionView*>(this->currentMoveable);
    itv->setName(arg1.toStdString());
}

void PetriProperties::on_le_itrans_prior_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_itrans_guard_textEdited(const QString &arg1)
{

}
