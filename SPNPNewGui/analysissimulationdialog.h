#ifndef ANALYSISSIMULATIONDIALOG_H
#define ANALYSISSIMULATIONDIALOG_H

#include <QDialog>
#include "highlighter.h"
#include "objs/net.h"
namespace Ui {
class AnalysisSimulationDialog;
}

class AnalysisSimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisSimulationDialog(QWidget *parent = 0);
    ~AnalysisSimulationDialog();

    void setNetData(spnp::Net *net);

private:
    Ui::AnalysisSimulationDialog *ui;
    Highlighter *hl;
};

#endif // ANALYSISSIMULATIONDIALOG_H
