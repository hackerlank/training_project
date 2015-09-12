#include "petriscene.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#include "diagram/arcs/ipetriarc.h"
#include "diagram/items/placeitem.h"
#include "diagram/items/fplaceitem.h"
#include "diagram/items/ttransitem.h"
#include "diagram/items/imtransitem.h"

#include "diagram/arcs/activatorarcitem.h"
#include "diagram/arcs/inhibitorarcitem.h"
#include "diagram/arcs/factivatorarcitem.h"

#include "objs/net.h"

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

    this->setBackgroundBrush(QBrush(0xAACACA));
}

void PetriScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    if(isItemOfType(IPetriArc::Type))
    {
        IPetriArc *item = qgraphicsitem_cast<IPetriArc*>(selectedItems().first());
        item->setColor(myLineColor);
        update();
    }
}

void PetriScene::setTextColor(const QColor &color)
{
    myTextColor = color;
    if(isItemOfType(PetriTextItem::Type))
    {
        PetriTextItem *item = qgraphicsitem_cast<PetriTextItem*>(selectedItems().first());
        item->setDefaultTextColor(myTextColor);
    }
}

void PetriScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    if(isItemOfType(IPetriItem::Type))
    {
        IPetriItem *item = qgraphicsitem_cast<IPetriItem*>(selectedItems().first());
        item->setBrush(myItemColor);
    }
}

void PetriScene::setFont(const QFont &font)
{
    myFont = font;
    if(isItemOfType(PetriTextItem::Type))
    {
        QGraphicsTextItem *item = qgraphicsitem_cast<QGraphicsTextItem*>(selectedItems().first());
        if(item)
            item->setFont(myFont);
    }
}
/*
void PetriScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->fillRect(rect, 0xFFECCC);
    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += gridSize){
        for (qreal y = top; y < rect.bottom(); y += gridSize){
            points.append(QPointF(x,y));
        }
    }
    painter->drawPoints(points.data(), points.size());
}*/

void PetriScene::load(spnp::IData *data)
{
    spnp::Net *netData = static_cast<spnp::Net*>(data);
    this->clear();
    for(unsigned int i=0, total=netData->getPlaces()->size(); i<total; ++i)
    {
        spnp::Place* place = netData->getPlaces()->at(i);
        this->insertItem(place, QPointF(place->x, place->y));
    }
    for(unsigned int i=0, total=netData->getTransitions()->size(); i<total; ++i)
    {
        spnp::ImmediateTransition* transition = netData->getTransitions()->at(i);
        this->insertItem(transition, QPointF(transition->x, transition->y));
    }
    for(unsigned int i=0, total=netData->getArcs()->size(); i<total; ++i)
    {
        spnp::Arc* arc = netData->getArcs()->at(i);
        //TODO inserir arco
        //this->insertArc(arc, QPointF(arc->x, arc->y));
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
        this->insertItem(nullptr, mouseEvent->scenePos());
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
    QGraphicsScene::mousePressEvent(mouseEvent);
    //aqui porque deve ser após a seleção de um item
    if(myMode == MoveItem)
        this->itemSelection();
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
        QList<QGraphicsItem*> items = this->selectedItems();
        for(int i =0; i<items.size(); ++i)
        {
            repositionItem(items.at(i));
        }
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
                emit arcInserted(arc);
            }
        }
    }
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool PetriScene::isItemOfType(int type)
{
    foreach (QGraphicsItem *item, selectedItems())
    {
        if(item->type() == type)
            return true;
    }
    return false;//horrível dois returns :'(
}

void PetriScene::insertItem(spnp::IData *itemData, QPointF position)
{
    IPetriItem *item = nullptr;

    switch (myItemType)
    {
    case IPetriItem::Place:
        if(itemData == nullptr)
            itemData = new spnp::Place();
        item = new PlaceItem(itemData, myItemMenu);
        break;
    case IPetriItem::FPlace:
        if(itemData == nullptr)
            itemData = new spnp::FluidPlace();
        item = new FPlaceItem(itemData, myItemMenu);
        break;
    case IPetriItem::ITrans:
        if(itemData == nullptr)
            itemData = new spnp::ImmediateTransition();
        item = new ImTransItem(itemData, myItemMenu);
        break;
    case IPetriItem::TTrans:
        if(itemData == nullptr)
            itemData = new spnp::TimedTransition();
        item = new TTransItem(itemData, myItemMenu);
        break;
    default:
        break;
    }
    item->setBrush(myItemColor);
    addItem(item);
    item->setPos(position);
    repositionItem(item);
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
    emit itemDeleted();
}

void PetriScene::itemSelection()
{
    if(this->selectedItems().size() > 0)
    {
        emit itemSelected(this->selectedItems().at(0));
    }
}

void PetriScene::repositionItem(QGraphicsItem *item)
{
    int x = round(item->pos().x()/gridSize)*gridSize;
    int y = round(item->pos().y()/gridSize)*gridSize;

    item->setPos(x, y);
}
