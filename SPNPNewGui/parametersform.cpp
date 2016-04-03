#include "parametersform.h"
#include "ui_parametersform.h"

#include "parameteroptiondata.h"

ParametersForm::ParametersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersForm)
{
    ui->setupUi(this);
    this->netData = nullptr;
}

ParametersForm::~ParametersForm()
{
    delete ui;
}

void ParametersForm::setNetData(spnp::Net *net)
{
    this->netData = net;
    this->fillData();
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

void ParametersForm::fillData()
{
    //lugares
    std::vector<spnp::Place*>* places = this->netData->getPlaces();
    this->fillPlacesNames(this->ui->cb_place_steady, places);
    this->fillPlacesNames(this->ui->cb_place_time, places);
    this->fillPlacesNames(this->ui->cb_prob_place_steady, places);
    this->fillPlacesNames(this->ui->cb_prob_place_time, places);

    //transições
    std::vector<spnp::ImmediateTransition*>* transitions = this->netData->getTransitions();
    this->fillTransitionNames(this->ui->cb_t_tran_steady, transitions);
    this->fillTransitionNames(this->ui->cb_t_tran_time, transitions);
    this->fillTransitionNames(this->ui->cb_u_tran_steady, transitions);
    this->fillTransitionNames(this->ui->cb_u_tran_time, transitions);
}

void ParametersForm::fillPlacesNames(QComboBox *cb, std::vector<spnp::Place*> *places)
{
    cb->clear();
    if(places!=nullptr)
    {
        for(int i=0, total = places->size(); i< total; ++i)
        {
            spnp::Place* place = places->at(i);
            QString placeName = QString::fromStdString(place->getName());
            QVariant data(QString::fromStdString(place->id));
            cb->addItem(placeName, data);
        }
    }
}

void ParametersForm::fillTransitionNames(QComboBox *cb, std::vector<spnp::ImmediateTransition *> *transitions)
{
    cb->clear();
    if(transitions!=nullptr)
    {
        for(int i=0, total = transitions->size(); i< total; ++i)
        {
            spnp::ImmediateTransition* transition = transitions->at(i);
            QString placeName = QString::fromStdString(transition->getName());
            QVariant data(QString::fromStdString(transition->id));
            cb->addItem(placeName, data);
        }
    }
}
