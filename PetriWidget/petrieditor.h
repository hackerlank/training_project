#ifndef PETRIEDITOR_H
#define PETRIEDITOR_H

#include <QWidget>
#include "petriwidget_global.h"
#include "view/moveable.h"

namespace Ui {
class PetriEditor;
}

class PW_PUBLIC PetriEditor : public QWidget
{
    Q_OBJECT

public:
    explicit PetriEditor(QWidget *parent = 0);
    ~PetriEditor();

private slots:
    void on_petri_buttons_arc();

    void on_petri_buttons_arrow();

    void on_petri_buttons_fplace();

    void on_petri_buttons_inhibitor();

    void on_petri_buttons_itrans();

    void on_petri_buttons_place();

    void on_petri_buttons_ttrans();

    void onItemClick(Moveable *m);

private:
    Ui::PetriEditor *ui;
    Moveable* currentObject;
};

#endif // PETRIEDITOR_H
