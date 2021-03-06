#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

#include "objs/option.h"

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

    void loadOptions(spnp::Option *proj);

private slots:
    void on_rb_analysis_toggled(bool checked);

    void on_bt_box_accepted();

private:
    Ui::OptionsDialog *ui;
    spnp::Option *options;

    void saveOptions();
};

#endif // OPTIONSDIALOG_H
