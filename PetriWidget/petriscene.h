#ifndef PETRISCENE_H
#define PETRISCENE_H

#include <QGraphicsScene>
#include <QMenu>
#include <QFont>
#include <QColor>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "states.h"
#include "view/abstractlabeledmoveable.h"
//#include "petriwidget_global.h"

class PW_PUBLIC PetriScene:public QGraphicsScene
{
    Q_OBJECT
public:

    explicit PetriScene(QMenu* itemMenu, QObject *parent= nullptr);
    QFont font() const { return myFont; }
    QColor textColor() const { return myTextColor; }
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }
    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);
    void setFont(const QFont &font);

public slots:
    void setMode(spnp::CurrentState mode);

signals:
    void itemInserted(AbstractLabeledMoveable *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
    bool isItemChange(int type);

    QMenu *myItemMenu;
    spnp::CurrentState myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QFont myFont;
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;
};

#endif // PETRISCENE_H
