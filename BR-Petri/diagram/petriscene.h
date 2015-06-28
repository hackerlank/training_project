#ifndef PETRISCENE_H
#define PETRISCENE_H

//#include "abstractpetriitem.h"
#include "ipetriitem.h"
#include "petritextitem.h"

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
    enum Mode { InsItem, InsArc, InsText, MoveItem };

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
    void setItemtype(IPetriItem::PetriType type);
    void editorLostFocus(PetriTextItem *item);

signals:
    void itemInserted(IPetriItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
    bool isItemChange(int type);

    IPetriItem::PetriType myItemType;
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
};

#endif // PETRISCENE_H
