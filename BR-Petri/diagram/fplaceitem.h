#ifndef FPLACEITEM_H
#define FPLACEITEM_H

#include "diagram/abstractpetriitem.h"

class FPlaceItem : public AbstractPetriItem
{
public:
    FPlaceItem(QMenu *contextMenu, QGraphicsItem *parent=nullptr);
    virtual ~FPlaceItem();

protected:
    virtual void drawItem() override;
};

#endif // FPLACEITEM_H
