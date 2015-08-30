#include "activatorarcitem.h"

const qreal Pi = 3.14;

ActivatorArcItem::ActivatorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(startItem, endItem, parent)
{
    this->myArcType = IPetriArc::Activator;
}

ActivatorArcItem::~ActivatorArcItem()
{

}
