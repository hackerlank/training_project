#ifndef PLACEITEM_H
#define PLACEITEM_H

#include "abstractpetriitem.h"

class PlaceItem : public AbstractPetriItem
{
public:
    PlaceItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent=nullptr);
    virtual ~PlaceItem();

protected:
    virtual void drawItem() override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // PLACEITEM_H
