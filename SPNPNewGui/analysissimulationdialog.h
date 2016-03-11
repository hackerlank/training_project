#ifndef ANALYSISSIMULATIONDIALOG_H
#define ANALYSISSIMULATIONDIALOG_H

#include <QDialog>

namespace Ui {
class AnalysisSimulationDialog;
}

class AnalysisSimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisSimulationDialog(QWidget *parent = 0);
    ~AnalysisSimulationDialog();

private:
    Ui::AnalysisSimulationDialog *ui;
};

#endif // ANALYSISSIMULATIONDIALOG_H
