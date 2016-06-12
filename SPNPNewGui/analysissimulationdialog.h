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

private slots:
    void on_tabWidget_currentChanged(int index);

private:
    Ui::AnalysisSimulationDialog *ui;
    Highlighter *hl;
    spnp::Net *net;
};

#endif // ANALYSISSIMULATIONDIALOG_H
