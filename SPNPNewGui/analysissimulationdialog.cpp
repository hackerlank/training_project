#include "analysissimulationdialog.h"
#include "ui_analysissimulationdialog.h"

#include "objs/outputfunction.h"
#include "objs/net.h"
#include "cspl.h"

AnalysisSimulationDialog::AnalysisSimulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisSimulationDialog)
{
    ui->setupUi(this);
    this->hl = new Highlighter(this->ui->text_edit->document());
    this->net = nullptr;
}

AnalysisSimulationDialog::~AnalysisSimulationDialog()
{
    delete ui;
    delete hl;
}

void AnalysisSimulationDialog::setNetData(spnp::Net *net)
{
    this->net = net;
    this->ui->w_param->setNetData(net);
}

void AnalysisSimulationDialog::on_tabWidget_currentChanged(int index)
{
    if(index==1)
    {
        std::vector<spnp::OutputFunction> *out = this->ui->w_param->getOutputs();
        Cspl cspl;
        std::string ascii = cspl.to_ascii_c(net, out);

        this->ui->text_edit->setText(QString::fromStdString(ascii));
    }
}
