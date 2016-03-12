#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

#include "objs/project.h"

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

    void loadOptions(spnp::Project* proj);

private slots:
    void on_rb_analysis_toggled(bool checked);

private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
