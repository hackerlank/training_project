#ifndef PETRIBUTTONS_H
#define PETRIBUTTONS_H

#include "petriwidget_global.h"

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class PetriButtons;
}

class PW_PUBLIC PetriButtons : public QWidget
{
    Q_OBJECT

public:
    enum InputState
    {
        Select,
        Place,
        FluidPlace,
        ImmediateTransition,
        TimedTransition,
        Arc,
        Inhibitor
    };

    explicit PetriButtons(QWidget *parent = 0);
    ~PetriButtons();

    InputState getCurrentState();
    void setCurrentState(InputState state);

    void reset();
    void afterClick();

private slots:
    void on_pb_arrow_clicked();

    void on_pb_place_clicked();

    void on_pb_fplace_clicked();

    void on_pb_itrans_clicked();

    void on_pb_ttrans_clicked();

    void on_pb_arc_clicked();

    void on_pb_inhibitor_clicked();

private:
    Ui::PetriButtons *ui;

    QButtonGroup *buttonGroup;
    InputState currentState;
};

#endif // PETRIBUTTONS_H
