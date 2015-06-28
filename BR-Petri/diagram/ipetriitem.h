#ifndef IPETRIITEM_H
#define IPETRIITEM_H

#include <QGraphicsPolygonItem>

class AbstractPetriArc;

class IPetriItem : public QGraphicsPolygonItem
{
public:
    enum { Type = UserType + 15 };
    enum PetriType { Place, FPlace, ITrans, TTrans };

    IPetriItem(QGraphicsItem *parent):QGraphicsPolygonItem(parent) { }
    virtual ~IPetriItem() { }

    virtual void removeArc(AbstractPetriArc *arc) = 0;
    virtual void addArc(AbstractPetriArc* arc) = 0;
    virtual bool isPlace() = 0;
    virtual bool isTransition() = 0;

    virtual void drawItem() = 0;
};

#endif // IPETRIITEM_H
