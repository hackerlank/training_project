#ifndef PETRIVIEW_H
#define PETRIVIEW_H

#include <QGraphicsView>

#include "diagram/petriscene.h"

class PetriView: public QGraphicsView
{
    Q_OBJECT
public:
    PetriView(QWidget *parent = nullptr);
    virtual ~PetriView();

    PetriScene* getScene() const;

public slots:
    void itemViewInserted(IPetriItem *item);
    void textViewInserted(QGraphicsTextItem *item);
    void itemViewSelected(QGraphicsItem *item);

private:
    PetriScene* scene;
};

#endif // PETRIVIEW_H
