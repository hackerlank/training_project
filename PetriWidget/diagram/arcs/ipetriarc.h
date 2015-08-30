#ifndef IPETRIARC_H
#define IPETRIARC_H

#include <QGraphicsLineItem>
#include "diagram/items/ipetriitem.h"

class QGraphicsLineItem;

class IPetriArc : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };
    enum ArcType { Activator, Inhibitor, FActivator };

    IPetriArc(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr)
        :QGraphicsLineItem(parent) { this->myStartItem = startItem; this->myEndItem = endItem;}
    virtual ~IPetriArc() { }

    virtual void setColor(const QColor &color) = 0;

    IPetriArc::ArcType arcType() const { return myArcType; }

    IPetriItem *startItem() const { return myStartItem; }
    IPetriItem *endItem() const { return myEndItem; }

    int type() const override { return Type; }

    virtual bool canConnect() = 0;
    virtual void updatePosition() = 0;

protected:
    virtual void paintHead(double angle) = 0;

    IPetriItem* myStartItem;
    IPetriItem* myEndItem;

    IPetriArc::ArcType myArcType;
};

#endif // IPETRIARC_H
