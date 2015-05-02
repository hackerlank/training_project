#ifndef PETRIWIDGET_H
#define PETRIWIDGET_H

#include <QGraphicsView>

#include "petriwidget_global.h"
#include "objs/net.h"
#include "states.h"

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
public slots:
    void zoomIn();
    void zoomOut();
    void showContextMenu(const QPoint& pos);

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
#endif
    void scaleView(qreal scaleFactor);

private:
    spnp::Net netData;

    int idPlace = 0;
    int idArc = 0;
    int idTransition = 0;

    void updateIds();

    int getNextPlace();
    int getNextTransition();
    int getNextArc();

    void clear();

    spnp::CurrentState currentState;
};

#endif // PETRIWIDGET_H
