#ifndef PETRIDESIGN_H
#define PETRIDESIGN_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class PetriDesign;
}

class PetriDesign : public QWidget
{
    Q_OBJECT

public:
    explicit PetriDesign(QWidget *parent = 0);
    ~PetriDesign();

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

private:
    Ui::PetriDesign *ui;

    QButtonGroup *bGroup;

    void addButtonsToGroup();
};

#endif // PETRIDESIGN_H
