#ifndef IPETRIITEM_H
#define IPETRIITEM_H

#include <QGraphicsPolygonItem>
#include "idata.h"

class IPetriArc;

class IPetriItem : public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 15 };
    enum PetriType { Place, FPlace, ITrans, TTrans };

    IPetriItem(spnp::IData* data, QMenu *contextMenu, QGraphicsItem *parent):QGraphicsPolygonItem(parent)
    {
        this->myContextMenu = contextMenu;
        this->data = data;
    }
    virtual ~IPetriItem() { delete this->data; }

    int type() const override { return Type; }

    IPetriItem::PetriType petriType() const { return myPetriType; }

    virtual void removeArc(IPetriArc *arc) = 0;
    virtual void removeArcs() = 0;
    virtual void addArc(IPetriArc* arc) = 0;
    virtual bool isPlace() = 0;
    virtual bool isTransition() = 0;

    virtual void drawItem() = 0;

    spnp::IData* getData() const { return this->data; }

protected:
    IPetriItem::PetriType myPetriType;
    QMenu *myContextMenu;

private:
    spnp::IData* data;

};

#endif // IPETRIITEM_H
