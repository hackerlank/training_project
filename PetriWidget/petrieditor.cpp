#include "petrieditor.h"
#include "ui_petrieditor.h"

PetriEditor::PetriEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriEditor)
{
    ui->setupUi(this);
    connect(this->ui->widget, SIGNAL(itemSelected(QGraphicsItem*)),
            this->ui->widget_2, SLOT(onItemSelected(QGraphicsItem*)));

    this->project = nullptr;
}

PetriEditor::~PetriEditor()
{
    this->closeProject();
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

void PetriEditor::closeProject()
{
    delete this->project;
    this->setEnabled(false);
}

void PetriEditor::startProject(spnp::Project *project)
{
    this->project = project;
    this->setEnabled(true);
}
