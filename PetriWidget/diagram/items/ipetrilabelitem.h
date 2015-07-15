#ifndef IPETRILABELITEM_H
#define IPETRILABELITEM_H

#include <QGraphicsSimpleTextItem>

class IPetriLabelItem : public QGraphicsSimpleTextItem
{
public:
    enum { Type = UserType + 20 };

    IPetriLabelItem(const QString &text, QGraphicsItem *parent = 0, bool moveable=true)
        :QGraphicsSimpleTextItem(text, parent) { this->moveable = moveable; }
    virtual ~IPetriLabelItem() { }

    int type() const override { return Type; }

protected:
    bool moveable;
};

#endif // IPETRILABELITEM_H
