#ifndef ITRANSITIONVIEW_H
#define ITRANSITIONVIEW_H

#include "view/abstractlabeledmoveable.h"
#include "objs/transition.h"

class PW_PUBLIC ImmediateTransitionView : public AbstractLabeledMoveable
{
public:
    ImmediateTransitionView(PetriWidget *pWidget, spnp::Transition* transition);
    ~ImmediateTransitionView();

    enum { Type = UserType + 2 };

    int type() const override { return Type; }

    QPainterPath shape() const override;
    virtual MoveableTypes getTypeName() const;

    std::string getName() const;
    virtual void setName(std::string name) override;
protected:
    virtual void paintDraw(QPainter *painter) override;

    virtual void itemMoved(QPointF point);

    spnp::Transition* transition;
};

#endif // ITRANSITION_H
