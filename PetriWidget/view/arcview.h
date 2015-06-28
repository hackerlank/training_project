#ifndef ARCVIEW_H
#define ARCVIEW_H

#include <QGraphicsLineItem>

#include "objs/arc.h"
//TODO verificar inibidor
#include "arrowitem.h"

#include "view/abstractlabeledmoveable.h"

class PW_PUBLIC ArcView : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    ArcView(AbstractLabeledMoveable *startItem, AbstractLabeledMoveable *endItem,
      QGraphicsItem *parent = 0);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void setColor(const QColor &color) { myColor = color; }
    AbstractLabeledMoveable *startItem() const { return myStartItem; }
    AbstractLabeledMoveable *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    AbstractLabeledMoveable *myStartItem;
    AbstractLabeledMoveable *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARCVIEW_H
