#ifndef INHIBITORARCITEM_H
#define INHIBITORARCITEM_H

#include "diagram/arcs/abstractpetriarc.h"

class InhibitorArcItem : public AbstractPetriArc
{
public:
    InhibitorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~InhibitorArcItem();

    virtual bool canConnect() override;

protected:
    virtual void paintHead(double angle);

    virtual QColor getBrushColor();
};

#endif // INHIBITORARCITEM_H
