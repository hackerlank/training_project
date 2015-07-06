#ifndef PETRIVIEW_H
#define PETRIVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

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

    //zoom
    void scalingTime(qreal x);
    void animFinished();

#ifndef QT_NO_WHEELEVENT
protected:
    //zoom
    void wheelEvent(QWheelEvent *event) override;
#endif

private:
    PetriScene* scene;

    //zoom
    int _numScheduledScalings;
};

#endif // PETRIVIEW_H
