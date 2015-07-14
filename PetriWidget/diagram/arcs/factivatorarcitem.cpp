#include "factivatorarcitem.h"

const qreal Pi = 3.14;

FActivatorArcItem::FActivatorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(startItem, endItem, parent)
{

}

FActivatorArcItem::~FActivatorArcItem()
{

}

QColor FActivatorArcItem::getBrushColor()
{
    return Qt::green;
}

QColor FActivatorArcItem::getPenColor()
{
    return Qt::green;
}
