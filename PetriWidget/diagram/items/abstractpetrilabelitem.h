#ifndef ABSTRACTPETRILABELITEM_H
#define ABSTRACTPETRILABELITEM_H

#include "diagram/items/ipetrilabelitem.h"

class AbstractPetriLabelItem : public IPetriLabelItem
{
public:
    AbstractPetriLabelItem(const QString &text, QGraphicsItem *parent = 0, bool moveable=true);
    virtual ~AbstractPetriLabelItem();

    virtual void setText(const QString &text);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *evt) override;//clear selection
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *evt) override;//save changes to obj

protected:
    virtual void saveText(const QString &text)=0;
    virtual void savePosition(const QPointF pos)=0;
};

#endif // ABSTRACTPETRILABELITEM_H
