#include "ttransitem.h"

#include <QGraphicsSceneMouseEvent>
#include "objs/timedtransition.h"

TTransItem::TTransItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(id, contextMenu, parent)
{
    myPetriType = IPetriItem::TTrans;

    drawItem();
}

TTransItem::~TTransItem()
{

}

void TTransItem::updateLabel(spnp::IData *data)
{
    spnp::TimedTransition *it = static_cast<spnp::TimedTransition*>(data);
    this->setLabel(it->getName());
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
    //TODO conferir
    QGraphicsItem::mouseMoveEvent(event);/*
    spnp::TimedTransition *_data = static_cast<spnp::TimedTransition*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();*/
}

void TTransItem::onContextMenu(QAction *act)
{
    if(act->data().toBool())
    {

    }
}
