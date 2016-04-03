#include "analysissimulationdialog.h"
#include "ui_analysissimulationdialog.h"

AnalysisSimulationDialog::AnalysisSimulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisSimulationDialog)
{
    ui->setupUi(this);
    this->hl = new Highlighter(this->ui->text_edit->document());
}

AnalysisSimulationDialog::~AnalysisSimulationDialog()
{
    delete ui;
    delete hl;
}

void AnalysisSimulationDialog::setNetData(spnp::Net *net)
{
    this->ui->w_param->setNetData(net);
}
