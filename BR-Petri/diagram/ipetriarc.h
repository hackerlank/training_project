#ifndef IPETRIARC_H
#define IPETRIARC_H

#include <QGraphicsLineItem>
#include "diagram/ipetriitem.h"

class QGraphicsLineItem;

class IPetriArc : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };
    enum ArcType { Activator, Inhibitor };

    IPetriArc(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr)
        :QGraphicsLineItem(parent) { this->myStartItem = startItem; this->myEndItem = endItem;}
    virtual ~IPetriArc() { }

    virtual void setColor(const QColor &color) = 0;
    IPetriItem *startItem() const { return myStartItem; }
    IPetriItem *endItem() const { return myEndItem; }

    int type() const Q_DECL_OVERRIDE { return Type; }

    virtual bool canConnect() = 0;
    virtual void updatePosition() = 0;

protected:
    virtual void paintHead(double angle) = 0;

    IPetriItem* myStartItem;
    IPetriItem* myEndItem;
};

#endif // IPETRIARC_H
