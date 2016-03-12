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
        switch (opt->analysis) {
        default:
        case spnp::Option::AnalysisOptions::STEADY_STATE:
            this->ui->rb_steadystate->setChecked(true);
            break;
        case spnp::Option::AnalysisOptions::TRANSIENT:
            this->ui->rb_transient->setChecked(true);
            break;
        case spnp::Option::AnalysisOptions::BOTH:
            this->ui->rb_both->setChecked(true);
            break;
        }
        this->ui->cb_sensitivity->setChecked(opt->sensitivity);

        this->ui->cb_absorbing_marking->setChecked(opt->absorbinMarking);

        this->ui->cb_absorbing_marking->setChecked(opt->absorbinMarking);
        this->ui->cb_trans_van_loops->setChecked(opt->trasientVanishingLoops);
        this->ui->cb_trans_ini_mark->setChecked(opt->transientInitialMarking);
        this->ui->cb_vanishing_ini_val->setChecked(opt->vanishingInitialMarking);

        this->ui->combo_approach->setCurrentIndex(opt->approach);

        this->ui->combo_steadystate->setCurrentIndex(opt->steadyStateMethod);

        index = opt->transientMethod  == spnp::Option::TransientMethod::STANDART_UNIFORMIZATION ? 0 : 1;
        this->ui->combo_transient_method->setCurrentIndex(index);

        this->ui->le_max_iter->setText(QString::number(opt->maxIterations));
        this->ui->le_min_prec->setText(QString::number(opt->minPrecision));
        this->ui->le_m0_ret_rate->setText(QString::number(opt->m0returnRate));

        this->ui->cb_compute->setChecked(opt->computeCumulativeProbabilities);
        this->ui->cb_steadystate_detect->setChecked(opt->steadyStateDetection);

        this->ui->combo_vanishing_mark->setCurrentIndex(opt->vanishing);

        //simulação
        switch (opt->simulationMethod) {
        default:
        case spnp::Option::SimulationMethod::DISCRET_EVENT_INDEPENDENT:
        case spnp::Option::SimulationMethod::DISCRET_EVENT_BATCH:
            this->ui->stacked_simulation->setCurrentIndex(0);
            break;
        case spnp::Option::SimulationMethod::RESTART:
            this->ui->stacked_simulation->setCurrentIndex(1);
            break;
        case spnp::Option::SimulationMethod::SPLITTING:
            this->ui->stacked_simulation->setCurrentIndex(2);
            break;
        }

        this->ui->combo_method_sim->setCurrentIndex(opt->simulationMethod);

        this->ui->rb_num_repl->setChecked(opt->isReplication);
        this->ui->rb_error_giv->setChecked(!opt->isReplication);
        this->ui->le_number_repl->setText(QString::number(opt->replicationOrErrorValue));

        this->ui->combo_req_conf->setCurrentIndex(opt->confidence);

        this->ui->le_length_it->setText(QString::number(opt->lengthSimulation));
        this->ui->le_comp_fluid->setText(QString::number(opt->fluidPlacesContent));
        this->ui->le_comp_firing->setText(QString::number(opt->firingTimeConflict));
        this->ui->le_seed->setText(QString::number(opt->seed));
        this->ui->cb_print->setChecked(opt->printReport);
        this->ui->le_warm_up->setText(QString::number(opt->warmup));
    }
}

void OptionsDialog::on_rb_analysis_toggled(bool checked)
{
    this->ui->tab_an->setEnabled(checked);
    this->ui->tab_sim->setEnabled(!checked);
}
