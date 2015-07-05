#ifndef ABSTRACTPETRIARC_H
#define ABSTRACTPETRIARC_H

#include <QGraphicsLineItem>

//#include "abstractpetriitem.h"
//#include "ipetriitem.h"
#include "diagram/ipetriarc.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class AbstractPetriArc : public IPetriArc
{
public:
    AbstractPetriArc(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~AbstractPetriArc();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) override { myColor = color; }

    virtual bool canConnect() override;
    void updatePosition() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr) override;

    virtual void paintHead(double angle) override;

    QPolygonF myHead;

    virtual QColor getBrushColor();
    virtual QColor getPenColor();

private:
    QColor myColor;
};

#endif // ABSTRACTPETRIARC_H
