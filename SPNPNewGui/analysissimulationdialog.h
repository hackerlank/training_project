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

signals:
    void startSimulation(std::string ascii_c);

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_box_accepted();

private:
    Ui::AnalysisSimulationDialog *ui;
    Highlighter *hl;
    spnp::Net *net;

    std::string getProjectStr();
    std::string ascii;
};

#endif // ANALYSISSIMULATIONDIALOG_H
