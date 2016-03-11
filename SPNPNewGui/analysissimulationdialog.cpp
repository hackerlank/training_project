#include "analysissimulationdialog.h"
#include "ui_analysissimulationdialog.h"

AnalysisSimulationDialog::AnalysisSimulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisSimulationDialog)
{
    ui->setupUi(this);
}

AnalysisSimulationDialog::~AnalysisSimulationDialog()
{
    delete ui;
}
