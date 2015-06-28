#ifndef INHIBITORARCITEM_H
#define INHIBITORARCITEM_H

#include "diagram/abstractpetriarc.h"

class InhibitorArcItem : public AbstractPetriArc
{
public:
    InhibitorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~InhibitorArcItem();

    virtual bool canConnect() override;

protected:
    virtual void paintHead(double angle);
};

#endif // INHIBITORARCITEM_H
