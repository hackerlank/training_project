#include "abstractmoveable.h"

#include <QPainter>
#include <QStyleOption>

AbstractMoveable::AbstractMoveable(PetriWidget *pWidget):
    parentGraph(pWidget)
{
    setZValue(-1);
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);

    this->color_black = QColor(0,0,0,255);
    this->color_white = QColor(255, 255, 255, 255);
    this->color_blue = QColor(0x10, 0x4e, 0x8b, 255);
    this->selected = false;
}

AbstractMoveable::~AbstractMoveable()
{

}

QRectF AbstractMoveable::boundingRect() const
{
    return QRectF( -_W_/2, -_H_/2, _W_, _H_);
}

void AbstractMoveable::setSelected(bool b)
{
    this->selected = b;
}

void AbstractMoveable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush b(color_white);
    if(!(option->state & QStyle::State_Sunken))
    {
        color_white.setAlpha(150);
    }
    else
        color_white.setAlpha(255);
    painter->setBrush(b);

    painter->setPen(QPen(getBrushColor(), 0));
    this->paintDraw(painter);
}

QPolygonF AbstractMoveable::polygon()
{
    QPolygonF pol;
    pol << QPointF(-_W_/2, -_H_/2) << QPointF(_W_/2, -_H_/2)
        << QPointF(_W_/2, _H_/2) << QPointF(-_W_/2, _H_/2);
    return pol;
}

QVariant AbstractMoveable::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
    {
        this->itemMoved(value.toPointF());
        /*foreach (Edge *edge, edgeList)
            edge->adjust();
        graph->itemMoved();*/

        break;
    }
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void AbstractMoveable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void AbstractMoveable::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QColor AbstractMoveable::getBrushColor()
{
    return this->selected ? this->color_blue : this->color_black;
}
