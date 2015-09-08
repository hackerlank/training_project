#ifndef PETRIEDITOR_H
#define PETRIEDITOR_H

#include <QWidget>
#include <QGraphicsItem>
#include <QListWidgetItem>

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

private slots:
    void on_lw_nets_itemClicked(QListWidgetItem *item);
    void showContextMenuForListOfNets(const QPoint &p);

private:
    Ui::PetriEditor *ui;
    spnp::Project* project;

    void removeNetFromList(QString id);

    void loadNetIntoDesign(spnp::Net* net);
};

#endif // PETRIEDITOR_H
