#include "petridesign.h"
#include "ui_petridesign.h"

PetriDesign::PetriDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriDesign)
{
    ui->setupUi(this);
}

PetriDesign::~PetriDesign()
{
    delete ui;
}
