#ifndef PETRIDESIGN_H
#define PETRIDESIGN_H

#include <QWidget>
#include <QButtonGroup>
#include <QGraphicsItem>

#include "idata.h"

namespace Ui {
class PetriDesign;
}

class PetriDesign : public QWidget
{
    Q_OBJECT

public:
    explicit PetriDesign(QWidget *parent = 0);
    ~PetriDesign();

    bool isLocked();
    void setLocked(bool l);

    void close();
    void load(spnp::IData *data);

signals:
    void itemSelected(QGraphicsItem* item);

private slots:
    void on_bt_normal_clicked();

    void on_bt_place_clicked();

    void on_bt_fplace_clicked();

    void on_bt_ttrans_clicked();

    void on_bt_itrans_clicked();

    void on_bt_remove_clicked();

    void on_bt_arc_clicked();

    void on_bt_iarc_clicked();

    void on_bt_farc_clicked();


private slots:
    void afterClickAction();
    void afterSelectionAction(QGraphicsItem *item);

private:
    Ui::PetriDesign *ui;

    QButtonGroup *bGroup;

    void addButtonsToGroup();
};

#endif // PETRIDESIGN_H
