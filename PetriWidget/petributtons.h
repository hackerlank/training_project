#ifndef PETRIBUTTONS_H
#define PETRIBUTTONS_H

#include <QGroupBox>

#include "petriwidget_global.h"

class PW_PUBLIC PetriButtons : public QGroupBox
{
    Q_OBJECT
public:
    PetriButtons(QWidget* parent=0);
    ~PetriButtons();
};

#endif // PETRIBUTTONS_H
