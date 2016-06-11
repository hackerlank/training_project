#ifndef ITRANSITEM_H
#define ITRANSITEM_H

#include "diagram/items/abstractpetriitem.h"

class ImTransItem : public AbstractPetriItem
{
public:
    ImTransItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~ImTransItem();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void updateLabel(spnp::IData *data) override;
protected:
    virtual void drawItem() override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void onContextMenu(QAction* act) override;
};

#endif // ITRANSITEM_H
