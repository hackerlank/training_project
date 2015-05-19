#ifndef LABELVIEW_H
#define LABELVIEW_H

//#include "petriwidget_global.h"
#include "objs/label.h"
#include "view/abstractmoveable.h"

#include <QGraphicsSimpleTextItem>

class PW_PUBLIC LabelView : public QGraphicsSimpleTextItem
{
public:
    LabelView(AbstractMoveable *m);
    ~LabelView();

    spnp::Label *getLabel() const;

    void setText(std::string text);

    virtual AbstractMoveable::MoveableTypes getTypeName() const;
protected:
    virtual void itemMoved(QPointF point);
private:
    spnp::Label* label;
};

#endif // LABELVIEW_H
