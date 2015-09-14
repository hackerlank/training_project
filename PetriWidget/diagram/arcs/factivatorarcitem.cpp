#include "factivatorarcitem.h"

const qreal Pi = 3.14;

FActivatorArcItem::FActivatorArcItem(std::string id, IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(id, startItem, endItem, parent)
{
    this->myArcType = IPetriArc::FActivator;
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
