#ifndef PETRILABELITEM_H
#define PETRILABELITEM_H

#include "diagram/abstractpetrilabelitem.h"

class PetriLabelItem : public AbstractPetriLabelItem
{
public:
    PetriLabelItem(const QString &text, QGraphicsItem *parent = 0, bool moveable=true);
    virtual ~PetriLabelItem();

protected:
    virtual void saveText(const QString &text) override;
    virtual void savePosition(const QPointF pos) override;
};

#endif // PETRILABELITEM_H
