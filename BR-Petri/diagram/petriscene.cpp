#include "petriscene.h"

#include "diagram/arcs/ipetriarc.h"
#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>

#include "diagram/items/placeitem.h"
#include "diagram/items/fplaceitem.h"
#include "diagram/items/ttransitem.h"
#include "diagram/items/imtransitem.h"

#include "diagram/arcs/activatorarcitem.h"
#include "diagram/arcs/inhibitorarcitem.h"
#include "diagram/arcs/factivatorarcitem.h"

PetriScene::PetriScene(QMenu *itemMenu, QObject *parent)
    :QGraphicsScene(parent)
{
    this->myItemMenu = itemMenu;
    myMode = MoveItem;
    myItemType = IPetriItem::Place;
    myArcType = IPetriArc::Activator;
    line = nullptr;
    textItem = nullptr;
    myItemColor = Qt::white;
    myTextColor = Qt::black;
    myLineColor = Qt::black;
}

void PetriScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    if(isItemChange(IPetriArc::Type))
    {
        IPetriArc *item = qgraphicsitem_cast<IPetriArc*>(selectedItems().first());
        item->setColor(myLineColor);
        update();
    }
}

void PetriScene::setTextColor(const QColor &color)
{
    myTextColor = color;
    if(isItemChange(PetriTextItem::Type))
    {
        PetriTextItem *item = qgraphicsitem_cast<PetriTextItem*>(selectedItems().first());
        item->setDefaultTextColor(myTextColor);
    }
}

void PetriScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    if(isItemChange(IPetriItem::Type))
    {
        IPetriItem *item = qgraphicsitem_cast<IPetriItem*>(selectedItems().first());
        item->setBrush(myItemColor);
    }
}

void PetriScene::setFont(const QFont &font)
{
    myFont = font;
    if(isItemChange(PetriTextItem::Type))
    {
        QGraphicsTextItem *item = qgraphicsitem_cast<QGraphicsTextItem*>(selectedItems().first());
        if(item)
            item->setFont(myFont);
    }
}

void PetriScene::setMode(PetriScene::Mode mode)
{
    this->myMode = mode;
}

void PetriScene::setItemType(IPetriItem::PetriType type)
{
    this->myItemType = type;
}

void PetriScene::setArcType(IPetriArc::ArcType type)
{
    this->myArcType = type;
}

void PetriScene::editorLostFocus(PetriTextItem *item)
{
    QTextCursor cursor = item->textCursor();
    cursor.clearSelection();
    item->setTextCursor(cursor);

    if(item->toPlainText().isEmpty())
    {
        removeItem(item);
        item->deleteLater();
    }
}

void PetriScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() != Qt::LeftButton)
        return;

    switch (myMode)
    {
    case InsItem:
        this->insertItem(mouseEvent->scenePos());
        break;
    case InsArc:
        this->insertArc(mouseEvent->scenePos());
        break;
    case InsText:
        this->insertText(mouseEvent->scenePos());
        break;
    case RemoveItem:
        this->deleteItem();
        break;
    default:
        break;
    }
    this->clearSelection();
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void PetriScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(myMode == InsArc && line != nullptr)
    {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else if(myMode == MoveItem)
    {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void PetriScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(line != nullptr && myMode == InsArc)
    {
        QList<QGraphicsItem *>startItems = items(line->line().p1());
        if(startItems.count() && startItems.first() == line)
        {
            startItems.removeFirst();
        }
        QList<QGraphicsItem *>endItems = items(line->line().p2());
        if(endItems.count() && endItems.first() == line)
        {
            endItems.removeFirst();
        }

        removeItem(line);
        delete line;

        if(startItems.count() > 0 &&
                endItems.count() > 0 &&
                startItems.first()->type() == IPetriItem::Type &&
                endItems.first()->type() == IPetriItem::Type)
        {
            IPetriItem *start = qgraphicsitem_cast<IPetriItem*>(startItems.first());
            IPetriItem *end = qgraphicsitem_cast<IPetriItem*>(endItems.first());

            if(start != end &&
                    ((start->isPlace() && end->isTransition()) || (start->isTransition() && end->isPlace())))
            {
                IPetriArc *arc = nullptr;
                switch (myArcType) {
                case IPetriArc::Activator:
                    arc = new ActivatorArcItem(start,end);
                    break;
                case IPetriArc::Inhibitor:
                    arc = new InhibitorArcItem(start, end);
                    break;
                case IPetriArc::FActivator:
                    arc = new FActivatorArcItem(start, end);
                    break;
                default:
                    break;
                }

                arc->setColor(myLineColor);
                start->addArc(arc);
                end->addArc(arc);
                arc->setZValue(-1000.0);
                addItem(arc);
                arc->updatePosition();
            }
        }
    }
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool PetriScene::isItemChange(int type)
{
    foreach (QGraphicsItem *item, selectedItems())
    {
        if(item->type() == type)
            return true;
    }
    return false;//horrível dois returns :'(
}

void PetriScene::insertItem(QPointF position)
{
    IPetriItem *item = nullptr;
    switch (myItemType)
    {
    case IPetriItem::Place:
        item = new PlaceItem(myItemMenu);
        break;
    case IPetriItem::FPlace:
        item = new FPlaceItem(myItemMenu);
        break;
    case IPetriItem::ITrans:
        item = new ImTransItem(myItemMenu);
        break;
    case IPetriItem::TTrans:
        item = new TTransItem(myItemMenu);
        break;
    default:
        break;
    }
    item->setBrush(myItemColor);
    addItem(item);
    item->setPos(position);
    emit itemInserted(item);
}

void PetriScene::insertArc(QPointF position)
{
    line = new QGraphicsLineItem(QLineF(position, position));
    line->setPen(QPen(myLineColor, 2));
    addItem(line);
}

void PetriScene::insertText(QPointF position)
{
    textItem = new PetriTextItem();
    textItem->setFont(myFont);
    textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    textItem->setZValue(1000.0);
    connect(textItem, SIGNAL(lostFocus(PetriTextItem*)),
            this, SLOT(editorLostFocus(PetriTextItem*)));
    connect(textItem, SIGNAL(selectedChange(QGraphicsItem*)),
            this, SLOT(itemSelected(QGraphicsItem*)));
    addItem(textItem);
    textItem->setDefaultTextColor(myTextColor);
    textItem->setPos(position);
    emit textInserted(textItem);
}

void PetriScene::deleteItem()
{
    foreach (QGraphicsItem *item, this->selectedItems())
    {
        if(item->type() == IPetriArc::Type)
        {
            this->removeItem(item);
            IPetriArc *arc = qgraphicsitem_cast<IPetriArc*>(item);
            arc->startItem()->removeArc(arc);
            arc->endItem()->removeArc(arc);
            delete item;
        }
    }

    foreach (QGraphicsItem *item, this->selectedItems())
    {
        if (item->type() == IPetriItem::Type)
            qgraphicsitem_cast<IPetriItem *>(item)->removeArcs();
        this->removeItem(item);
        delete item;
    }
}
