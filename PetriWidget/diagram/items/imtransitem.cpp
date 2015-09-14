#include "imtransitem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "objs/immediatetransition.h"

ImTransItem::ImTransItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(id, contextMenu, parent)
{
    myPetriType = IPetriItem::ITrans;
    drawItem();
}

ImTransItem::~ImTransItem()
{

}

void ImTransItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    this->setBrush(QBrush(Qt::black));
    AbstractPetriItem::paint(painter, option, widget);
}

void ImTransItem::drawItem()
{
    const int vert = 30;
    const int hor = 8;
    QPainterPath path;
    path.addRect(-hor/2, -vert/2, hor, vert);
    myPolygon = path.toFillPolygon();
    AbstractPetriItem::drawItem();
}

void ImTransItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    //TODO verificar
    /*spnp::ImmediateTransition *_data = static_cast<spnp::ImmediateTransition*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();*/
}
