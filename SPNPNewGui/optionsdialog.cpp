#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
    this->options = nullptr;
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::loadOptions(spnp::Option *opt)
{
    this->options = opt;
    this->ui->tab_sim->setEnabled(false);
    if(options!= nullptr)
    {
        this->ui->rb_analysis->setChecked(options->isNumericalAnalysis);
        this->ui->rb_simulation->setChecked(!options->isNumericalAnalysis);
        //opções
        this->ui->cb_reach->setChecked(options->reachabilityGraphSet);
        this->ui->cb_markov_chain->setChecked(options->markovChain);
        this->ui->cb_der_ctmc->setChecked(options->derivativeOfCTMC);
        this->ui->cb_prob->setChecked(options->probabilities);
        this->ui->cb_prob_dtmc->setChecked(options->probabilitiesDTMC);
        this->ui->cb_dot->setChecked(options->dotGraphLanguage);

        if(options->isNumericalAnalysis) //análise
        {
            switch (options->analysis) {
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
            this->ui->cb_sensitivity->setChecked(options->sensitivity);

            this->ui->cb_absorbing_marking->setChecked(options->absorbinMarking);

            this->ui->cb_absorbing_marking->setChecked(options->absorbinMarking);
            this->ui->cb_trans_van_loops->setChecked(options->trasientVanishingLoops);
            this->ui->cb_trans_ini_mark->setChecked(options->transientInitialMarking);
            this->ui->cb_vanishing_ini_val->setChecked(options->vanishingInitialMarking);

            this->ui->combo_approach->setCurrentIndex(options->approach);

            this->ui->combo_steadystate->setCurrentIndex(options->steadyStateMethod);

            this->ui->combo_transient_method->setCurrentIndex(options->transientMethod);

            this->ui->le_max_iter->setText(QString::number(options->maxIterations));
            this->ui->le_min_prec->setText(QString::number(options->minPrecision));
            this->ui->le_m0_ret_rate->setText(QString::number(options->m0returnRate));

            this->ui->cb_compute->setChecked(options->computeCumulativeProbabilities);
            this->ui->cb_steadystate_detect->setChecked(options->steadyStateDetection);

            this->ui->combo_vanishing_mark->setCurrentIndex(options->vanishing);
        }
        else //simulação
        {
            switch (options->simulationMethod) {
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

            this->ui->combo_method_sim->setCurrentIndex(options->simulationMethod);

            this->ui->rb_num_repl->setChecked(options->isReplication);
            this->ui->rb_error_giv->setChecked(!options->isReplication);
            this->ui->le_number_repl->setText(QString::number(options->replicationOrErrorValue));

            this->ui->combo_req_conf->setCurrentIndex(options->confidence);

            this->ui->le_length_it->setText(QString::number(options->lengthSimulation));
            this->ui->le_comp_fluid->setText(QString::number(options->fluidPlacesContent));
            this->ui->le_comp_firing->setText(QString::number(options->firingTimeConflict));
            this->ui->le_seed->setText(QString::number(options->seed));
            this->ui->cb_print->setChecked(options->printReport);
            this->ui->le_warm_up->setText(QString::number(options->warmup));

            //todo daqui
            this->ui->cb_output_usual->setChecked(options->outputUsual);

            this->ui->cb_finish->setChecked(options->isFinishEach);
            this->ui->le_a_num_pre_sim->setText(QString::number(options->numPreSim));
            this->ui->cb_a_pre_sim->setChecked(options->isPreSim);
            this->ui->le_a_num_import->setText(QString::number(options->numImport));

            this->ui->le_a_1->setText(options->a1);
            this->ui->le_a_2->setText(options->a2);
            this->ui->le_a_3->setText(options->a3);
            this->ui->le_a_4->setText(options->a4);
            this->ui->le_a_5->setText(options->a5);
            this->ui->le_a_6->setText(options->a6);

            //split
            this->ui->le_stop_num->setText(QString::number(options->stopNum));
            this->ui->le_b_num_pre_sim->setText(QString::number(options->numPreSimB));
            this->ui->cb_b_pre_sim->setChecked(options->isPreSimB);
            this->ui->le_b_num_import->setText(QString::number(options->numImportB));

            this->ui->le_b_1->setText(options->b1);
            this->ui->le_b_2->setText(options->b2);
            this->ui->le_b_3->setText(options->b3);
            this->ui->le_b_4->setText(options->b4);
            this->ui->le_b_5->setText(options->b5);
            this->ui->le_b_6->setText(options->b6);
        }
    }
}

void OptionsDialog::on_rb_analysis_toggled(bool checked)
{
    this->ui->tab_an->setEnabled(checked);
    this->ui->tab_sim->setEnabled(!checked);
}

void OptionsDialog::saveOptions()
{
    if(this->options!=nullptr)
    {
        options->isNumericalAnalysis = ui->rb_analysis->isChecked();
        //opções
        options->reachabilityGraphSet = ui->cb_reach->isChecked();
        options->markovChain = ui->cb_markov_chain->isChecked();
        options->derivativeOfCTMC = ui->cb_der_ctmc->isChecked();
        options->probabilities = ui->cb_prob->isChecked();
        options->probabilitiesDTMC = ui->cb_prob_dtmc->isChecked();
        options->dotGraphLanguage = ui->cb_dot->isChecked();

        if(options->isNumericalAnalysis) //análise
        {
            if(this->ui->rb_steadystate->isChecked())
            {
                options->analysis = spnp::Option::AnalysisOptions::STEADY_STATE;
            }
            else if(this->ui->rb_transient->isChecked())
            {
                options->analysis = spnp::Option::AnalysisOptions::TRANSIENT;
            }
            else
            {
                options->analysis = spnp::Option::AnalysisOptions::BOTH;
            }

            options->sensitivity = ui->cb_sensitivity->isChecked();

            options->absorbinMarking = ui->cb_absorbing_marking->isChecked();

            options->absorbinMarking = ui->cb_absorbing_marking->isChecked();
            options->trasientVanishingLoops = ui->cb_trans_van_loops->isChecked();
            options->transientInitialMarking = ui->cb_trans_ini_mark->isChecked();
            options->vanishingInitialMarking = ui->cb_vanishing_ini_val->isChecked();

            options->approach = static_cast<spnp::Option::Approach>(ui->combo_approach->currentIndex());
            options->steadyStateMethod = static_cast<spnp::Option::SteadStateMethod>(ui->combo_steadystate->currentIndex());
            options->transientMethod = static_cast<spnp::Option::TransientMethod>(this->ui->combo_transient_method->currentIndex());

            options->maxIterations = ui->le_max_iter->text().toInt();
            options->minPrecision = ui->le_min_prec->text().toDouble();
            options->m0returnRate = ui->le_m0_ret_rate->text().toDouble();

            options->computeCumulativeProbabilities = ui->cb_compute->isChecked();
            options->steadyStateDetection = ui->cb_steadystate_detect->isChecked();

            options->vanishing = static_cast<spnp::Option::VanishingMarkings>(ui->combo_vanishing_mark->currentIndex());
        }
        else //simulação
        {
            options->simulationMethod = static_cast<spnp::Option::SimulationMethod>(ui->combo_method_sim->currentIndex());

            options->isReplication = ui->rb_num_repl->isChecked();
            options->replicationOrErrorValue = ui->le_number_repl->text().toDouble();

            options->confidence = static_cast<spnp::Option::RequiredConfidence>(ui->combo_req_conf->currentIndex());

            options->lengthSimulation = ui->le_length_it->text().toDouble();
            options->fluidPlacesContent = ui->le_comp_fluid->text().toDouble();
            options->firingTimeConflict = ui->le_comp_firing->text().toDouble();
            options->seed = ui->le_seed->text().toDouble();

            options->printReport = ui->cb_print->isChecked();
            options->warmup = ui->le_warm_up->text().toDouble();
        }
    }
}

void OptionsDialog::on_bt_box_accepted()
{
    this->saveOptions();
}
