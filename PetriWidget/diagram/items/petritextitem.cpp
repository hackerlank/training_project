#include "petritextitem.h"

PetriTextItem::PetriTextItem(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

QVariant PetriTextItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change==QGraphicsItem::ItemSelectedHasChanged)
    {
        emit selectedChange(this);
    }
    return value;
}

void PetriTextItem::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void PetriTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

