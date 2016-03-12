#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::loadOptions(spnp::Project *proj)
{
    spnp::Option *opt = proj->getOptions();
    this->ui->tab_sim->setEnabled(false);
    if(opt!= nullptr)
    {
        this->ui->rb_analysis->setChecked(opt->isNumericalAnalysis);
        this->ui->rb_simulation->setChecked(!opt->isNumericalAnalysis);
        //opções
        this->ui->cb_reach->setChecked(opt->reachabilityGraphSet);
        this->ui->cb_markov_chain->setChecked(opt->markovChain);
        this->ui->cb_der_ctmc->setChecked(opt->derivativeOfCTMC);
        this->ui->cb_prob->setChecked(opt->probabilities);
        this->ui->cb_prob_dtmc->setChecked(opt->probabilitiesDTMC);
        this->ui->cb_dot->setChecked(opt->dotGraphLanguage);

        //análise


        //simulação
    }
}

void OptionsDialog::on_rb_analysis_toggled(bool checked)
{
    this->ui->tab_an->setEnabled(checked);
    this->ui->tab_sim->setEnabled(!checked);
}
