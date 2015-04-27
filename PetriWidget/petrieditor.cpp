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
