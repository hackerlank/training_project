#ifndef ACTIVATORARCITEM_H
#define ACTIVATORARCITEM_H

#include "diagram/arcs/abstractpetriarc.h"

class ActivatorArcItem : public AbstractPetriArc
{
public:
    ActivatorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~ActivatorArcItem();
};

#endif // ACTIVATORARCITEM_H
