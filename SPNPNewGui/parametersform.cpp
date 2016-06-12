#include "parametersform.h"

#include "ui_parametersform.h"
#include "outputwidget.h"

ParametersForm::ParametersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametersForm)
{
    ui->setupUi(this);
    this->netData = nullptr;
    this->outputs = new std::vector<spnp::OutputFunction>();
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

void ParametersForm::on_bt_place_steady_clicked()
{
    std::string data = this->ui->cb_place_steady->currentData().toString().toStdString();

    spnp::OutputFunction out(spnp::OutputFunction::EXPECTED_TOKEN_PLACE_STEADY, data);
    this->outputs->push_back(out);
    this->createOutputButton(out);
}

void ParametersForm::on_bt_place_time_clicked()
{
    std::string data = this->ui->cb_place_time->currentData().toString().toStdString();
    std::string opt = this->ui->le_place_time->text().toStdString();
    spnp::OutputFunction out(spnp::OutputFunction::EXPECTED_TOKEN_PLACE_TIME, data, opt);
    this->outputs->push_back(out);
}

void ParametersForm::on_output_remove_clicked(std::string id)
{
    this->removeOutputButton(id);
}

void ParametersForm::createOutputButton(spnp::OutputFunction func)
{
    OutputWidget *ow = new OutputWidget(func.id);
    ow->setText(func.getDescription());

    QLayout* l = this->ui->scrollAreaWidgetContents_2->layout();
    if(l != nullptr)
    {
        l->addWidget(ow);
    }
}

void ParametersForm::removeOutputButton(std::string id)
{

}
