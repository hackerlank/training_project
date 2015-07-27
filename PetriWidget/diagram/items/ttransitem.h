#ifndef TTRANS_H
#define TTRANS_H

#include "diagram/items/abstractpetriitem.h"

class TTransItem : public AbstractPetriItem
{
public:
    TTransItem(spnp::IData *data, QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~TTransItem();

protected:
    virtual void drawItem() override;
};

#endif // TTRANS_H
