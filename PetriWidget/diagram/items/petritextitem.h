#ifndef PETRITEXTITEM_H
#define PETRITEXTITEM_H

#include <QGraphicsTextItem>
#include <QPen>

class QFocusEvent;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;

class PetriTextItem : public QGraphicsTextItem
{
    Q_OBJECT
//TODO : tornar possível acrescentar texto
public:
    enum { Type = UserType + 3};

    PetriTextItem(QGraphicsItem *parent=nullptr);

    int type() const override { return Type; }

signals:
    void lostFocus(PetriTextItem *item);
    void selectedChange(QGraphicsItem *item);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void focusOutEvent(QFocusEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // PETRITEXTITEM_H
