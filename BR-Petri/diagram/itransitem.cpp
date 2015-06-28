#include "itransitem.h"

#include <QPainter>

ITransItem::ITransItem(QMenu *contextMenu, QGraphicsItem *parent):AbstractPetriItem(contextMenu, parent)
{
    myPetriType = IPetriItem::ITrans;
    drawItem();
}

ITransItem::~ITransItem()
{

}

void ITransItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    this->setBrush(QBrush(Qt::black));
    AbstractPetriItem::paint(painter, option, widget);
}

void ITransItem::drawItem()
{
    const int vert = 30;
    const int hor = 8;
    QPainterPath path;
    path.addRect(-hor/2, -vert/2, hor, vert);
    myPolygon = path.toFillPolygon();
    AbstractPetriItem::drawItem();
}
