#ifndef PLACEITEM_H
#define PLACEITEM_H

#include "abstractpetriitem.h"

class PlaceItem : public AbstractPetriItem
{
public:
    PlaceItem(std::string id, QGraphicsItem *parent=nullptr);
    virtual ~PlaceItem();

    virtual void updateLabel(spnp::IData *data) override;

    void updateToken(QString value);

protected:
    virtual void drawItem() override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    IPetriLabelItem *tokenLabel;
};

#endif // PLACEITEM_H
