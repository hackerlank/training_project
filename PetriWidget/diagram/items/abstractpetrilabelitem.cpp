#include "abstractpetrilabelitem.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

AbstractPetriLabelItem::AbstractPetriLabelItem(const QString &text, QGraphicsItem *parent, bool moveable)
    :IPetriLabelItem(text, parent, moveable)
{
    setFlag(QGraphicsItem::ItemIsMovable, moveable);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
}

AbstractPetriLabelItem::~AbstractPetriLabelItem()
{

}

void AbstractPetriLabelItem::setText(const QString &text)
{
    this->saveText(text);
    QGraphicsSimpleTextItem::setText(text);
}

void AbstractPetriLabelItem::mousePressEvent(QGraphicsSceneMouseEvent *evt)
{
    scene()->clearSelection();
    QGraphicsSimpleTextItem::mousePressEvent(evt);
}

void AbstractPetriLabelItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *evt)
{
    if(evt->button() == Qt::LeftButton)
    {
        this->savePosition(evt->pos());
    }
    QGraphicsSimpleTextItem::mouseReleaseEvent(evt);
}

