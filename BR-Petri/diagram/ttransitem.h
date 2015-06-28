#ifndef TTRANS_H
#define TTRANS_H

#include "abstractpetriitem.h"

class TTransItem : public AbstractPetriItem
{
public:
    TTransItem(QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~TTransItem();

protected:
    virtual void drawItem() override;
};

#endif // TTRANS_H
