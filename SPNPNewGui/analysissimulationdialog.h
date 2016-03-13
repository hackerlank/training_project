#ifndef ANALYSISSIMULATIONDIALOG_H
#define ANALYSISSIMULATIONDIALOG_H

#include <QDialog>
#include "highlighter.h"

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
    Highlighter *hl;
};

#endif // ANALYSISSIMULATIONDIALOG_H
