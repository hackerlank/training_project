#ifndef ITRANSITEM_H
#define ITRANSITEM_H

#include "abstractpetriitem.h"

class ITransItem : public AbstractPetriItem
{
public:
    ITransItem(QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~ITransItem();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    virtual void drawItem() override;
};

#endif // ITRANSITEM_H
