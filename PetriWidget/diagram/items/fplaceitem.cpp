#include "fplaceitem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "objs/fluidplace.h"

FPlaceItem::FPlaceItem(spnp::IData *data, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(data, contextMenu, parent)
{
    myPetriType = IPetriItem::FPlace;

    drawItem();
}

FPlaceItem::~FPlaceItem()
{

}

void FPlaceItem::drawItem()
{
    this->setFillRule(Qt::WindingFill);
    const int outer = 40;
    const int inner = 30;
    QPainterPath path;
    path.addEllipse(-outer/2, -outer/2, outer, outer);

    path.addEllipse(-inner/2, -inner/2, inner, inner);
    myPolygon = path.toFillPolygon();
    AbstractPetriItem::drawItem();
}

void FPlaceItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    spnp::FluidPlace *_data = static_cast<spnp::FluidPlace*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();
}
