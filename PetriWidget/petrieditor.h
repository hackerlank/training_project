#ifndef PETRIEDITOR_H
#define PETRIEDITOR_H

#include <QWidget>
#include <QGraphicsItem>

namespace Ui {
class PetriEditor;
}

class PetriEditor : public QWidget
{
    Q_OBJECT

public:
    explicit PetriEditor(QWidget *parent = 0);
    ~PetriEditor();

    bool isLocked();
    void setLocked(bool l);

private:
    Ui::PetriEditor *ui;

};

#endif // PETRIEDITOR_H
