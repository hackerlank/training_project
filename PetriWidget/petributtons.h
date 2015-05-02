#ifndef PETRIBUTTONS_H
#define PETRIBUTTONS_H

#include <QWidget>
#include <QButtonGroup>

#include "petriwidget_global.h"

namespace Ui {
class PetriButtons;
}

class PW_PUBLIC PetriButtons : public QWidget
{
    Q_OBJECT

public:
    explicit PetriButtons(QWidget *parent = 0);
    ~PetriButtons();

signals:
    void arrow();
    void arc();
    void inhibitor();
    void place();
    void fplace();
    void itrans();
    void ttrans();

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
    QButtonGroup *btGroup;
};

#endif // PETRIBUTTONS_H
