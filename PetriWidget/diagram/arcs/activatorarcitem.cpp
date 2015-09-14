#include "activatorarcitem.h"

const qreal Pi = 3.14;

ActivatorArcItem::ActivatorArcItem(std::string id, IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(id, startItem, endItem, parent)
{
    this->myArcType = IPetriArc::Activator;
}

ActivatorArcItem::~ActivatorArcItem()
{

}
