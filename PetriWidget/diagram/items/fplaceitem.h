#ifndef FPLACEITEM_H
#define FPLACEITEM_H

#include "diagram/items/abstractpetriitem.h"

class FPlaceItem : public AbstractPetriItem
{
public:
    FPlaceItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent=nullptr);
    virtual ~FPlaceItem();

protected:
    virtual void drawItem() override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // FPLACEITEM_H
