#ifndef FACTIVATORARCITEM_H
#define FACTIVATORARCITEM_H

#include "diagram/arcs/abstractpetriarc.h"

class FActivatorArcItem : public AbstractPetriArc
{
public:
    FActivatorArcItem(std::string id, IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~FActivatorArcItem();

protected:
    virtual QColor getBrushColor();
    virtual QColor getPenColor();
};


#endif // FACTIVATORARCITEM_H
