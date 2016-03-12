#ifndef PREFERENCESETUPFORM_H
#define PREFERENCESETUPFORM_H

#include <QAbstractButton>
#include <QDialog>
#include <QFileDialog>

namespace Ui {
class PreferenceSetupForm;
}

class PathSetupForm : public QDialog
{
    Q_OBJECT

public:
    explicit PathSetupForm(QWidget *parent = 0);
    ~PathSetupForm();

private slots:
    void on_pb_spnp_clicked();

    void on_pb_examples_clicked();

    void on_pb_plots_clicked();

    void on_bb_ok_cancel_clicked(QAbstractButton *button);

private:
    Ui::PreferenceSetupForm *ui;
    QFileDialog *fileDialog;

    void loadOptions();
    void saveOptions();
    void showError(QString title, QString message);
};

#endif // PREFERENCESETUPFORM_H
