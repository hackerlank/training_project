#include "petrieditor.h"
#include "ui_petrieditor.h"

PetriEditor::PetriEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriEditor)
{
    ui->setupUi(this);
}

PetriEditor::~PetriEditor()
{
    delete ui;
}

bool PetriEditor::isLocked()
{
    return this->ui->widget->isLocked();
}

void PetriEditor::setLocked(bool l)
{
    this->ui->widget->setLocked(l);
}
