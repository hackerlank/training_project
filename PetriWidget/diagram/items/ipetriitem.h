#ifndef IPETRIITEM_H
#define IPETRIITEM_H

#include <QGraphicsPolygonItem>

class IPetriArc;

class IPetriItem : public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 15 };
    enum PetriType { Place, FPlace, ITrans, TTrans };

    IPetriItem(QMenu *contextMenu, QGraphicsItem *parent):QGraphicsPolygonItem(parent) { this->myContextMenu = contextMenu; }
    virtual ~IPetriItem() { }

    int type() const override { return Type; }

    IPetriItem::PetriType petriType() const { return myPetriType; }

    virtual void removeArc(IPetriArc *arc) = 0;
    virtual void removeArcs() = 0;
    virtual void addArc(IPetriArc* arc) = 0;
    virtual bool isPlace() = 0;
    virtual bool isTransition() = 0;

    virtual void drawItem() = 0;

protected:
    IPetriItem::PetriType myPetriType;
    QMenu *myContextMenu;
};

#endif // IPETRIITEM_H
