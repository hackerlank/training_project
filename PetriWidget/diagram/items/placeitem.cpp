#include "placeitem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "objs/place.h"

PlaceItem::PlaceItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(id, contextMenu, parent)
{
    myPetriType = IPetriItem::Place;

    drawItem();
}

PlaceItem::~PlaceItem()
{

}

void PlaceItem::drawItem()
{
    const int radius = 40;
    QPainterPath path;
    path.addEllipse(-radius/2, -radius/2, radius, radius);
    myPolygon = path.toFillPolygon();
    AbstractPetriItem::drawItem();
}

void PlaceItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    //TODO conferir
    /*spnp::Place *_data = static_cast<spnp::Place*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();*/
}
