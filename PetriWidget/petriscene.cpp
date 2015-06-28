#include "petriscene.h"

#include "view/arcview.h"

PetriScene::PetriScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
    myMode = spnp::CurrentState::ARROW;
    line = 0;
    myItemColor = Qt::white;
    myTextColor = Qt::black;
    myLineColor = Qt::black;
}

void PetriScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    if (isItemChange(ArcView::Type))
    {
        ArcView *item = qgraphicsitem_cast<ArcView *>(selectedItems().first());
        item->setColor(myLineColor);
        update();
    }
}

void PetriScene::setTextColor(const QColor &color)
{
    myTextColor = color;
    /*if (isItemChange(DiagramTextItem::Type)) {
        DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        item->setDefaultTextColor(myTextColor);
    }*/
}

void PetriScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    /*if (isItemChange(DiagramItem::Type)) {
        DiagramItem *item = qgraphicsitem_cast<DiagramItem *>(selectedItems().first());
        item->setBrush(myItemColor);
    }*/
}

void PetriScene::setFont(const QFont &font)
{
    myFont = font;

    /*if (isItemChange(DiagramTextItem::Type)) {
        QGraphicsTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
        //At this point the selection can change so the first selected item might not be a DiagramTextItem
        if (item)
            item->setFont(myFont);
    }*/
}

void PetriScene::setMode(spnp::CurrentState mode)
{
    this->myMode = mode;
}

void PetriScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    AbstractLabeledMoveable *item;
    /*switch (myMode) {
        case InsertItem:
            item = new DiagramItem(myItemType, myItemMenu);
            item->setBrush(myItemColor);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
        case InsertLine:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));
            line->setPen(QPen(myLineColor, 2));
            addItem(line);
            break;
        case InsertText:
            textItem = new DiagramTextItem();
            textItem->setFont(myFont);
            textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            textItem->setZValue(1000.0);
            connect(textItem, SIGNAL(lostFocus(DiagramTextItem*)),
                    this, SLOT(editorLostFocus(DiagramTextItem*)));
            connect(textItem, SIGNAL(selectedChange(QGraphicsItem*)),
                    this, SIGNAL(itemSelected(QGraphicsItem*)));
            addItem(textItem);
            textItem->setDefaultTextColor(myTextColor);
            textItem->setPos(mouseEvent->scenePos());
            emit textInserted(textItem);
    default:
        ;
    }*/
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void PetriScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == spnp::CurrentState::ARC && line != nullptr)
    {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else if (myMode == spnp::CurrentState::ARROW)
    {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void PetriScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != nullptr && myMode == spnp::CurrentState::ARC)
    {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
                startItems.first()->type() == AbstractLabeledMoveable::Type &&
                endItems.first()->type() == AbstractLabeledMoveable::Type &&
                startItems.first() != endItems.first())
        {
            AbstractLabeledMoveable *startItem = qgraphicsitem_cast<AbstractLabeledMoveable *>(startItems.first());
            AbstractLabeledMoveable *endItem = qgraphicsitem_cast<AbstractLabeledMoveable *>(endItems.first());
            ArcView *arrow = new ArcView(startItem, endItem);
            arrow->setColor(myLineColor);
            /*startItem->addArrow(arrow);
            endItem->addArrow(arrow);*/
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();
        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool PetriScene::isItemChange(int type)
{
    foreach (QGraphicsItem *item, selectedItems()) {
        if (item->type() == type)
            return true;
    }
    return false;
}
