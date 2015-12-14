#ifndef TTRANS_H
#define TTRANS_H

#include "diagram/items/abstractpetriitem.h"

class TTransItem : public AbstractPetriItem
{
public:
    TTransItem(std::string id, QMenu *contextMenu, QGraphicsItem *parent = nullptr);
    virtual ~TTransItem();

    void updateLabel(spnp::IData *data) override;

protected:
    virtual void drawItem() override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // TTRANS_H
