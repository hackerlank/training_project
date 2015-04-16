#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include <QGraphicsItem>
#include <QGraphicsWidget>

class PetriWidget;
class PlaceView : public QGraphicsItem
{
public:
    PlaceView(PetriWidget *pWidget);
    ~PlaceView();

    enum { Type = UserType + 1 };

    int type() const Q_DECL_OVERRIDE { return Type; }

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    PetriWidget *graph;

    static const int RADIUS;
};

#endif // PLACEVIEW_H
