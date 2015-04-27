#include "petributtons.h"
#include "ui_petributtons.h"

PetriButtons::PetriButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriButtons)
{
    ui->setupUi(this);

    //botões
    buttonGroup = new QButtonGroup(this->ui->groupBox);
    buttonGroup->addButton(this->ui->pb_arc);
    buttonGroup->addButton(this->ui->pb_arrow);
    buttonGroup->addButton(this->ui->pb_fplace);
    buttonGroup->addButton(this->ui->pb_place);
    buttonGroup->addButton(this->ui->pb_inhibitor);
    buttonGroup->addButton(this->ui->pb_itrans);
    buttonGroup->addButton(this->ui->pb_ttrans);

    this->currentState = Select;
}

PetriButtons::~PetriButtons()
{
    delete ui;
}

PetriButtons::InputState PetriButtons::getCurrentState()
{
    return this->currentState;
}

void PetriButtons::setCurrentState(PetriButtons::InputState state)
{
    this->currentState = state;
}

void PetriButtons::reset()
{
    this->ui->pb_arrow->setChecked(true);
}

void PetriButtons::afterClick()
{
    if(!this->ui->cb_lock->isChecked())
    {
        this->reset();
    }
}

void PetriButtons::on_pb_arrow_clicked()
{
    this->currentState = Select;
}

void PetriButtons::on_pb_place_clicked()
{
    this->currentState = Place;
}

void PetriButtons::on_pb_fplace_clicked()
{
    this->currentState = FluidPlace;
}

void PetriButtons::on_pb_itrans_clicked()
{
    this->currentState = ImmediateTransition;
}

void PetriButtons::on_pb_ttrans_clicked()
{
    this->currentState = TimedTransition;
}

void PetriButtons::on_pb_arc_clicked()
{
    this->currentState = Arc;
}

void PetriButtons::on_pb_inhibitor_clicked()
{
    this->currentState = Inhibitor;
}
