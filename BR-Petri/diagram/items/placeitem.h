#ifndef PLACEITEM_H
#define PLACEITEM_H

#include "abstractpetriitem.h"

class PlaceItem : public AbstractPetriItem
{
public:
    PlaceItem(QMenu *contextMenu, QGraphicsItem *parent=nullptr);
    virtual ~PlaceItem();

protected:
    virtual void drawItem() override;
};

#endif // PLACEITEM_H
