#ifndef PETRIEDITOR_H
#define PETRIEDITOR_H

#include <QWidget>
#include <QGraphicsItem>
#include "objs/project.h"

namespace Ui {
class PetriEditor;
}

class PetriEditor : public QWidget
{
    Q_OBJECT

public:
    explicit PetriEditor(QWidget *parent = 0);
    ~PetriEditor();

    //relativo ao botão 'travar'
    bool isLocked();
    void setLocked(bool l);

    void closeProject();
    void startProject(spnp::Project* project);

private:
    Ui::PetriEditor *ui;
    spnp::Project* project;
};

#endif // PETRIEDITOR_H
