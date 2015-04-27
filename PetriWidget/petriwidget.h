#ifndef PETRIWIDGET_H
#define PETRIWIDGET_H

#include <QGraphicsView>

#include "petriwidget_global.h"
#include "objs/net.h"

class PW_PUBLIC PetriWidget: public QGraphicsView
{
    Q_OBJECT
public:
    PetriWidget(QWidget *parent);
    ~PetriWidget();

    void createPlace(int x, int y);
    void createTransition(int x, int y);
    void createArc(int idP, int idT, bool fromPtoT);

    void removePlace(int id);
    void removeArc(int id);
    void removeTransition(int id);

    void itemMoved();

    void reset();
public slots:
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
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
};

#endif // PETRIWIDGET_H
