#ifndef ITRANSITEM_H
#define ITRANSITEM_H

#include "diagram/items/abstractpetriitem.h"

class ImTransItem : public AbstractPetriItem
{
public:
    ImTransItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~ImTransItem();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void drawItem() override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // ITRANSITEM_H
