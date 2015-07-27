#include "fplaceitem.h"

#include <QPainter>

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
