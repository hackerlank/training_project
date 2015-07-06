#ifndef PETRIITEM_H
#define PETRIITEM_H

#include <QList>
#include "diagram/items/ipetriitem.h"
#include "diagram/items/ipetrilabelitem.h"

class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;

class AbstractPetriItem : public IPetriItem
{
public:
    AbstractPetriItem(QMenu *contextMenu, QGraphicsItem *parent=nullptr);
    virtual ~AbstractPetriItem();

    virtual void removeArc(IPetriArc *arc) override;
    void removeArcs();
    IPetriItem::PetriType petriType() const { return myPetriType; }
    QPolygonF polygon() const { return myPolygon; }
    virtual void addArc(IPetriArc *arc) override;
    QPixmap image() const;

    virtual bool isPlace() override;
    virtual bool isTransition() override;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    IPetriItem::PetriType myPetriType;
    QPolygonF myPolygon;
    QMenu *myContextMenu;
    QList<IPetriArc*> arcs;

    IPetriLabelItem *myLabel;

    virtual void drawItem() override;
};

#endif // PETRIITEM_H
