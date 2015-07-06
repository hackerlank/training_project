#include "factivatorarcitem.h"

const qreal Pi = 3.14;

FActivatorArcItem::FActivatorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(startItem, endItem, parent)
{

}

FActivatorArcItem::~FActivatorArcItem()
{

}
/*
void FActivatorArcItem::paintHead(double angle)
{

}*/

QColor FActivatorArcItem::getBrushColor()
{
    return Qt::blue;
}

QColor FActivatorArcItem::getPenColor()
{
    return Qt::blue;
}
