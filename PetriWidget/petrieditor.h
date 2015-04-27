#ifndef PETRIEDITOR_H
#define PETRIEDITOR_H

#include <QWidget>

#include "petriwidget_global.h"

namespace Ui {
class PetriEditor;
}

class PW_PUBLIC PetriEditor : public QWidget
{
    Q_OBJECT

public:
    explicit PetriEditor(QWidget *parent = 0);
    ~PetriEditor();

private:
    Ui::PetriEditor *ui;
};

#endif // PETRIEDITOR_H
