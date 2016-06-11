#ifndef ABSTRACTPETRIARC_H
#define ABSTRACTPETRIARC_H

#include <QGraphicsLineItem>

//#include "abstractpetriitem.h"
//#include "ipetriitem.h"

#include "diagram/arcs/ipetriarc.h"
#include "diagram/items/ipetrilabelitem.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class AbstractPetriArc : public IPetriArc
{
public:
    AbstractPetriArc(std::string id, IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent=nullptr);
    virtual ~AbstractPetriArc();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) override { myColor = color; }

    virtual bool canConnect() override;
    void updatePosition() override;

    virtual void updateLabel(QString str);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr) override;

    virtual void paintHead(double angle) override;

    QPolygonF myHead;

    virtual QColor getBrushColor();
    virtual QColor getPenColor();

    virtual void updateLabelPosition();

    IPetriLabelItem *myLabel;

private:
    QColor myColor;
};

#endif // ABSTRACTPETRIARC_H
