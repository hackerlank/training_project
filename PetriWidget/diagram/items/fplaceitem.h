#ifndef FPLACEITEM_H
#define FPLACEITEM_H

#include "diagram/items/abstractpetriitem.h"

class FPlaceItem : public AbstractPetriItem
{
public:
    FPlaceItem(std::string id, QGraphicsItem *parent=nullptr);
    virtual ~FPlaceItem();

    virtual void updateLabel(spnp::IData *data) override;

    void updateToken(QString value);

protected:
    virtual void drawItem() override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    IPetriLabelItem *tokenLabel;
};

#endif // FPLACEITEM_H
