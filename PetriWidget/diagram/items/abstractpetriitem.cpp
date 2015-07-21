#include "abstractpetriitem.h"

#include "diagram/arcs/ipetriarc.h"
#include "diagram/items/petrilabelitem.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

AbstractPetriItem::AbstractPetriItem(QMenu *contextMenu, QGraphicsItem *parent):IPetriItem(contextMenu, parent)
{
    //drawItem();
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    this->myLabel = new PetriLabelItem("Name", this);
    this->myLabel->setPos(this->x() - this->myLabel->boundingRect().width()/2, this->y() - 35);
}

AbstractPetriItem::~AbstractPetriItem()
{
    delete this->myLabel;
}

void AbstractPetriItem::removeArc(IPetriArc *arc)
{
    int index = arcs.indexOf(arc);

    if(index != -1) arcs.removeAt(index);
}

void AbstractPetriItem::removeArcs()
{
    foreach (IPetriArc *arc, arcs)
    {
        arc->startItem()->removeArc(arc);
        arc->endItem()->removeArc(arc);
        scene()->removeItem(arc);
        delete arc;
    }
}

void AbstractPetriItem::addArc(IPetriArc *arc)
{
    this->arcs.append(arc);
}

QPixmap AbstractPetriItem::image() const
{
    QPixmap pixmap(250, 250);
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125,125);
    painter.drawPolyline(myPolygon);

    return pixmap;
}

bool AbstractPetriItem::isPlace()
{
    return (this->myPetriType == Place) || (this->myPetriType == FPlace) ;
}

bool AbstractPetriItem::isTransition()
{
    return (this->myPetriType == TTrans) || (this->myPetriType == ITrans) ;
}

void AbstractPetriItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    myContextMenu->exec(event->screenPos());
}

QVariant AbstractPetriItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change == QGraphicsItem::ItemPositionChange)
    {
        foreach (IPetriArc* arc, arcs)
        {
            arc->updatePosition();
        }
    }
    return value;
}

void AbstractPetriItem::drawItem()
{
    setPolygon(myPolygon);
}
