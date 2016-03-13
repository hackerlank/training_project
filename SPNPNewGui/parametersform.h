#ifndef PARAMETERSFORM_H
#define PARAMETERSFORM_H

#include <QWidget>

namespace Ui {
class ParametersForm;
}

class ParametersForm : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersForm(QWidget *parent = 0);
    ~ParametersForm();

private:
    Ui::ParametersForm *ui;
};

#endif // PARAMETERSFORM_H
