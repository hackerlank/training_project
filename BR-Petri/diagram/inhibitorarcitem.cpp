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
    qreal arcSize = 10;
    qreal arcSubSize = arcSize *0.9;

    myHead.clear();

    QPainterPath path;
    path.addEllipse(-arcSize/2, -arcSize/2, arcSize, arcSize);
    path.addEllipse(-arcSubSize/2, -arcSubSize/2, arcSubSize, arcSubSize);
    myHead = path.toFillPolygon();

    //myHead << line().p1() << arcP1 << arcP2;
}
