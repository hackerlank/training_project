#include "ttransitem.h"

#include <QGraphicsSceneMouseEvent>
#include "objs/timedtransition.h"

TTransItem::TTransItem(spnp::IData *data, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(data, contextMenu, parent)
{
    myPetriType = IPetriItem::TTrans;

    drawItem();
}

TTransItem::~TTransItem()
{

}

void TTransItem::drawItem()
{
    const int vert = 30;
    const int hor = 12;

    QPainterPath path;
    path.addRect(-hor/2, -vert/2, hor, vert);
    myPolygon = path.toFillPolygon();
    AbstractPetriItem::drawItem();
}

void TTransItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    spnp::TimedTransition *_data = static_cast<spnp::TimedTransition*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();
}
