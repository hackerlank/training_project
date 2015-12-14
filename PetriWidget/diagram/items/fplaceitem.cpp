#include "fplaceitem.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "objs/fluidplace.h"

#include "petrilabelitem.h"

FPlaceItem::FPlaceItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent)
    :AbstractPetriItem(id, contextMenu, parent)
{
    myPetriType = IPetriItem::FPlace;

    this->tokenLabel = new PetriLabelItem("0", this, false);
    this->tokenLabel->setPos(this->x() - this->tokenLabel->boundingRect().width()/2, this->x() - this->tokenLabel->boundingRect().height()/2);

    drawItem();
}

FPlaceItem::~FPlaceItem()
{

}

void FPlaceItem::updateLabel(spnp::IData *data)
{
    spnp::FluidPlace *fplace = static_cast<spnp::FluidPlace*>(data);
    this->setLabel(fplace->getName());
}

void FPlaceItem::updateToken(QString value)
{
    this->tokenLabel->setText(value);
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
    //TODO atualizar isso
    /*spnp::FluidPlace *_data = static_cast<spnp::FluidPlace*>(this->getData());
    _data->x = event->pos().x();
    _data->y = event->pos().y();*/
}
