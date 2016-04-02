#include "parametersform.h"
#include "ui_parametersform.h"

#include "parameteroptiondata.h"
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

void ParametersForm::on_bt_place_steady_clicked()
{
    std::string placeName = "test";
    ParameterOptionData* pod = new ParameterOptionData(ParameterOptionData::TYPE::PLACE,
                                                       ParameterOptionData::AMOUNT::SINGLE,
                                                       ParameterOptionData::TIME::STEADY,
                                                       placeName);
    (void)pod;
    //TODO : enviar
}
