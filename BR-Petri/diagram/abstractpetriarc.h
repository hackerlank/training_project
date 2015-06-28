#ifndef ABSTRACTPETRIARC_H
#define ABSTRACTPETRIARC_H

#include <QGraphicsLineItem>

//#include "abstractpetriitem.h"
#include "ipetriitem.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class AbstractPetriArc : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    AbstractPetriArc(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);

    int type() const Q_DECL_OVERRIDE { return Type; }
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void setColor(const QColor &color) { myColor = color; }
    IPetriItem *startItem() const { return myStartItem; }
    IPetriItem *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr) Q_DECL_OVERRIDE;

    virtual void paintHead(double angle);

    QPolygonF myHead;

private:
    IPetriItem* myStartItem;
    IPetriItem* myEndItem;
    QColor myColor;
};

#endif // ABSTRACTPETRIARC_H
