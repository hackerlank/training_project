#ifndef PARAMETERSFORM_H
#define PARAMETERSFORM_H

#include <QWidget>
#include <QComboBox>
#include "objs/net.h"
namespace Ui {
class ParametersForm;
}

class ParametersForm : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersForm(QWidget *parent = 0);
    ~ParametersForm();

    void setNetData(spnp::Net* net);

private slots:
    void on_bt_place_steady_clicked();

private:
    Ui::ParametersForm *ui;

    spnp::Net* netData;

    void fillData();
    void fillPlacesNames(QComboBox* cb, std::vector<spnp::Place *> *places);
    void fillTransitionNames(QComboBox* cb, std::vector<spnp::ImmediateTransition *> *transitions);
};

#endif // PARAMETERSFORM_H
