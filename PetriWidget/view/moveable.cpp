#include "moveable.h"

#include <QPainter>
#include <QStyleOption>

Moveable::Moveable(PetriWidget *pWidget):
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

Moveable::~Moveable()
{

}

QRectF Moveable::boundingRect() const
{
    return QRectF( -_W_/2, -_H_/2, _W_, _H_);
}

void Moveable::setSelected(bool b)
{
    this->selected = b;
}

void Moveable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QVariant Moveable::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{/*
    switch (change) {
    case ItemPositionHasChanged:
        /*foreach (Edge *edge, edgeList)
            edge->adjust();*/
    //graph->itemMoved();
    /* break;
    default:
        break;
    };*/

    return QGraphicsItem::itemChange(change, value);
}

void Moveable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Moveable::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QColor Moveable::getBrushColor()
{
    return this->selected ? this->color_blue : this->color_black;
}
