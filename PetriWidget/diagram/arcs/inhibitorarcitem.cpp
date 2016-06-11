#include "inhibitorarcitem.h"

InhibitorArcItem::InhibitorArcItem(IPetriItem *startItem, IPetriItem *endItem, QGraphicsItem *parent)
    :AbstractPetriArc(startItem, endItem, parent)
{

}

InhibitorArcItem::~InhibitorArcItem()
{

}

bool InhibitorArcItem::canConnect()
{
    return myStartItem->isPlace() && myEndItem->isTransition();
}

void InhibitorArcItem::paintHead(double angle)
{
    (void)angle;
    qreal circleSize = 4;

    QPointF p1 = line().p1()-QPointF(-cos(angle)*circleSize, sin(angle)*circleSize);

    QPainterPath path;
    path.addEllipse(p1, circleSize, circleSize);

    myHead.clear();

    myHead = path.toFillPolygon();
}

QColor InhibitorArcItem::getBrushColor()
{
    return Qt::white;
}
