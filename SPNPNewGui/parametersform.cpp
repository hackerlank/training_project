#include "parametersform.h"
#include "ui_parametersform.h"

ParametersForm::ParametersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersForm)
{
    ui->setupUi(this);
}

ParametersForm::~ParametersForm()
{
    delete ui;
}
