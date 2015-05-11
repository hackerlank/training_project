#ifndef PETRIPROPERTIES_H
#define PETRIPROPERTIES_H

#include <QWidget>
#include "view/moveable.h"

namespace Ui {
class PetriProperties;
}

class PetriProperties : public QWidget
{
    Q_OBJECT

public:
    explicit PetriProperties(QWidget *parent = 0);
    ~PetriProperties();

    void setMoveable(Moveable* m);

private:
    Ui::PetriProperties *ui;

    Moveable* currentMoveable;
};

#endif // PETRIPROPERTIES_H
