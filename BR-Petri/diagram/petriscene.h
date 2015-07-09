#ifndef PETRISCENE_H
#define PETRISCENE_H

//#include "diagram/items/abstractpetriitem.h"
#include "diagram/items/ipetriitem.h"
#include "diagram/arcs/ipetriarc.h"
#include "diagram/items/petritextitem.h"

#include <QGraphicsScene>

class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;

class PetriScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode { InsItem, InsArc, InsText, MoveItem, RemoveItem };

    explicit PetriScene(QMenu *itemMenu, QObject *parent=nullptr);
    QFont font() const { return myFont; }
    QColor textColor() const { return myTextColor; }
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }

    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);

    void setFont(const QFont &font);

public slots:
    void setMode(Mode mode);
    void setItemType(IPetriItem::PetriType type);
    void setArcType(IPetriArc::ArcType type);
    void editorLostFocus(PetriTextItem *item);

signals:
    void itemInserted(IPetriItem *item);
    void itemDeleted();
    void arcInserted(IPetriArc *arc);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    bool isItemChange(int type);

    IPetriItem::PetriType myItemType;
    IPetriArc::ArcType myArcType;
    QMenu *myItemMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QFont myFont;
    PetriTextItem *textItem;
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;

    void insertItem(QPointF position);
    void insertArc(QPointF position);
    void insertText(QPointF position);
    void deleteItem();
};

#endif // PETRISCENE_H
