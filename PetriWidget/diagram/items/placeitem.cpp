#include "placeitem.h"

#include <QPainter>

PlaceItem::PlaceItem(spnp::IData *data, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(data, contextMenu, parent)
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
