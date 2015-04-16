#include "placeview.h"

#include <QPainter>
#include <QStyleOption>

PlaceView::PlaceView(NetForm *netForm):graph(netForm)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}

PlaceView::~PlaceView()
{
    //remover lugar
}

QRectF PlaceView::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath PlaceView::shape() const
{
    QPainterPath path;
    path.addEllipse(-RADIUS/2, -RADIUS/2, RADIUS, RADIUS);
    return path;
}

void PlaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush b(0xeeeeee);
    if(option->state & QStyle::State_Sunken)
    {
        b.setColor(0xaaaaaa);
    }
    painter->setBrush(b);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-RADIUS/2, -RADIUS/2, RADIUS, RADIUS);
}

QVariant PlaceView::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        /*foreach (Edge *edge, edgeList)
            edge->adjust();*/
        //graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void PlaceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void PlaceView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

const int PlaceView::RADIUS = 20;
