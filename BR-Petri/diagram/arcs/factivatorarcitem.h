#ifndef FACTIVATORARCITEM_H
#define FACTIVATORARCITEM_H

#include "diagram/arcs/abstractpetriarc.h"

class FActivatorArcItem : public AbstractPetriArc
{
public:
    FActivatorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~FActivatorArcItem();

protected:
    //virtual void paintHead(double angle);

    virtual QColor getBrushColor();
    virtual QColor getPenColor();
};


#endif // FACTIVATORARCITEM_H
