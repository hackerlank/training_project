#ifndef PETRIWIDGET_H
#define PETRIWIDGET_H

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include "petriwidget_global.h"
#include "objs/net.h"
#include "states.h"
#include "view/abstractmoveable.h"

class PW_PUBLIC PetriWidget: public QGraphicsView
{
    Q_OBJECT
public:
    PetriWidget(QWidget *parent);
    ~PetriWidget();

    void createPlace(QMouseEvent* evt);
    void createFluidPlace(QMouseEvent* evt);
    void createTimedTransition(QMouseEvent *evt);
    void createImmediateTransition(QMouseEvent *evt);
    void createArc(QMouseEvent *evt);
    void createInhibitor(QMouseEvent *evt);

    void removePlace(int id);
    void removeArc(int id);
    void removeTransition(int id);

    void itemMoved();

    void reset();

    void setCurrentState(spnp::CurrentState state);

    void removeMoveable(AbstractMoveable* m);
signals:
    void itemSelected(AbstractMoveable* m);
public slots:
    void showContextMenu(const QPoint& pos);
    void scalingTime(qreal x);
    void animFinished();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
#endif

private:
    spnp::Net* netData;

    int idPlace = 0;
    int idArc = 0;
    int idTransition = 0;

    void updateIds();

    int getNextPlace();
    int getNextTransition();
    int getNextArc();

    void clear();

    spnp::CurrentState currentState;

    int _numScheduledScalings;

    QPointF startPoint;
    QGraphicsLineItem *line;
};

#endif // PETRIWIDGET_H
