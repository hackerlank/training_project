#include "placeitem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "objs/place.h"

#include "petrilabelitem.h"

PlaceItem::PlaceItem(std::string id, QGraphicsItem *parent)
    :AbstractPetriItem(id, nullptr, parent)
{
    myPetriType = IPetriItem::Place;

    this->tokenLabel = new PetriLabelItem("0", this, false);
    this->tokenLabel->setPos(this->x() - this->tokenLabel->boundingRect().width()/2, this->x() - this->tokenLabel->boundingRect().height()/2);

    drawItem();
}

PlaceItem::~PlaceItem()
{

}

void PlaceItem::updateLabel(spnp::IData *data)
{
    spnp::Place* place = static_cast<spnp::Place*>(data);
    this->setLabel(place->getName());
}

void PlaceItem::updateToken(QString value)
{
    this->tokenLabel->setText(value);
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
