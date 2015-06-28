#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <QGraphicsItem>
#include <QGraphicsWidget>
#include "petriwidget_global.h"

class PetriWidget;
class PW_PUBLIC AbstractMoveable : public QGraphicsItem
{
public:
    enum MoveableTypes
    {
        place = 0,
        fplace,
        itrans,
        ttrans,
        arc,
        farc,
        inhibitor,
        net,
        label
    };

    AbstractMoveable(PetriWidget *pWidget);
    ~AbstractMoveable();

    enum { Type = UserType + 0 };
    int type() const override { return Type; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override = 0;
    virtual MoveableTypes getTypeName() const = 0;
    virtual void setSelected(bool b);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPolygonF polygon();

protected:
    virtual void paintDraw(QPainter *painter)=0;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void itemMoved(QPointF point)=0;

    int _W_ = 20;
    int _H_ = 20;

    QColor color_white;
    QColor getBrushColor();

    PetriWidget *parentGraph;
private:
    bool selected;

    QColor color_blue;
    QColor color_black;
};

#endif // MOVEABLE_H
