#ifndef PETRIDESIGN_H
#define PETRIDESIGN_H

#include <QWidget>

namespace Ui {
class PetriDesign;
}

class PetriDesign : public QWidget
{
    Q_OBJECT

public:
    explicit PetriDesign(QWidget *parent = 0);
    ~PetriDesign();

private:
    Ui::PetriDesign *ui;
};

#endif // PETRIDESIGN_H
