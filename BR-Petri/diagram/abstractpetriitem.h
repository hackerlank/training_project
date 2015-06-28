#ifndef PETRIITEM_H
#define PETRIITEM_H

#include <QList>
#include "ipetriitem.h"

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

    virtual void removeArc(AbstractPetriArc *arc);
    void removeArcs();
    IPetriItem::PetriType petriType() const { return myPetriType; }
    QPolygonF polygon() const { return myPolygon; }
    virtual void addArc(AbstractPetriArc* arc);
    QPixmap image() const;
    int type() const Q_DECL_OVERRIDE { return Type; }

    virtual bool isPlace();
    virtual bool isTransition();

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

    IPetriItem::PetriType myPetriType;
    QPolygonF myPolygon;
    QMenu *myContextMenu;
    QList<AbstractPetriArc*> arcs;

    virtual void drawItem();
};

#endif // PETRIITEM_H
