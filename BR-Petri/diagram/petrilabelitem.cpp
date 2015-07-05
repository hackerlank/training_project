#include "petrilabelitem.h"

PetriLabelItem::PetriLabelItem(const QString &text, QGraphicsItem *parent, bool moveable)
    :AbstractPetriLabelItem(text, parent, moveable)
{

}

PetriLabelItem::~PetriLabelItem()
{

}

void PetriLabelItem::saveText(const QString &text)
{
    //TODO
    (void)text;
}

void PetriLabelItem::savePosition(const QPointF pos)
{
    //TODO
    (void)pos;
}

