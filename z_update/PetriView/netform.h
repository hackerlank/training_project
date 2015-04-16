#ifndef NETFORM_H
#define NETFORM_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "objs/net.h"

namespace Ui {
class NetForm;
}

class NetForm : public QGraphicsView
{
    Q_OBJECT

public:
    explicit NetForm(QWidget *parent = 0);
    ~NetForm();

    void createPlace(int x, int y);
    void createTransition(int x, int y);
    void createArc(int idP, int idT, bool fromPtoT);

    void removePlace(int id);
    void removeArc(int id);
    void removeTransition(int id);

    void itemMoved();

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
    Ui::NetForm *ui;
    spnp::Net netData;

    int idPlace = 0;
    int idArc = 0;
    int idTransition = 0;

    void updateIds();

    int getNextPlace();
    int getNextTransition();
    int getNextArc();
};

#endif // NETFORM_H
