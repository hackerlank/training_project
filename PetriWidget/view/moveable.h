#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <QGraphicsItem>
#include <QGraphicsWidget>
#include "petriwidget_global.h"

class PetriWidget;
class PW_PUBLIC Moveable : public QGraphicsItem
{
public:
    Moveable(PetriWidget *pWidget);
    ~Moveable();

    enum { Type = UserType + 0 };
    int type() const override { return Type; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual void paintDraw(QPainter *painter)=0;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    int _W_ = 20;
    int _H_ = 20;

    QColor color_black;
    QColor color_white;

    PetriWidget *parentGraph;
};

#endif // MOVEABLE_H
