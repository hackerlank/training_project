#include "projectform.h"
#include "ui_projectform.h"

ProjectForm::ProjectForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectForm)
{
    ui->setupUi(this);
}

ProjectForm::~ProjectForm()
{
    delete ui;
}
