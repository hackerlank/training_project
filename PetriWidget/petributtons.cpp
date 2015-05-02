#include "petributtons.h"
#include "ui_petributtons.h"

PetriButtons::PetriButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriButtons)
{
    ui->setupUi(this);
    this->btGroup = new QButtonGroup(this);
    this->btGroup->addButton(this->ui->pb_arc);
    this->btGroup->addButton(this->ui->pb_arrow);
    this->btGroup->addButton(this->ui->pb_fplace);
    this->btGroup->addButton(this->ui->pb_inhibitor);
    this->btGroup->addButton(this->ui->pb_itrans);
    this->btGroup->addButton(this->ui->pb_place);
    this->btGroup->addButton(this->ui->pb_ttrans);
}

PetriButtons::~PetriButtons()
{
    delete this->btGroup;
    delete ui;
}

void PetriButtons::on_pb_arrow_clicked()
{
    this->arrow();
}

void PetriButtons::on_pb_place_clicked()
{
    this->place();
}

void PetriButtons::on_pb_fplace_clicked()
{
    this->fplace();
}

void PetriButtons::on_pb_itrans_clicked()
{
    this->itrans();
}

void PetriButtons::on_pb_ttrans_clicked()
{
    this->ttrans();
}

void PetriButtons::on_pb_arc_clicked()
{
    this->arc();
}

void PetriButtons::on_pb_inhibitor_clicked()
{
    this->inhibitor();
}
