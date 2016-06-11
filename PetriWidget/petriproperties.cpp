#include "petriproperties.h"
#include "ui_petriproperties.h"

PetriProperties::PetriProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriProperties)
{
    ui->setupUi(this);
}

PetriProperties::~PetriProperties()
{
    delete ui;
}

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::setData()
{

}

void PetriProperties::on_le_itrans_name_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_itrans_prior_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_itrans_guard_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}
