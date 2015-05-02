#include "petrieditor.h"
#include "ui_petrieditor.h"

#include "states.h"

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

void PetriEditor::on_petri_buttons_arc()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::ARC);
}

void PetriEditor::on_petri_buttons_arrow()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::ARROW);
}

void PetriEditor::on_petri_buttons_fplace()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::FPLACE);
}

void PetriEditor::on_petri_buttons_inhibitor()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::INHIBITOR);
}

void PetriEditor::on_petri_buttons_itrans()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::ITRANS);
}

void PetriEditor::on_petri_buttons_place()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::PLACE);
}

void PetriEditor::on_petri_buttons_ttrans()
{
    this->ui->petri_view->setCurrentState(spnp::CurrentState::TTRANS);
}
