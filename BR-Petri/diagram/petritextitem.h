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

public:
    enum { Type = UserType + 3};

    PetriTextItem(QGraphicsItem *parent=nullptr);

    int type() const Q_DECL_OVERRIDE { return Type; }

signals:
    void lostFocus(PetriTextItem *item);
    void selectedChange(QGraphicsItem *item);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;
    void focusOutEvent(QFocusEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // PETRITEXTITEM_H
