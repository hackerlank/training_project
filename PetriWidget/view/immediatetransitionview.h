#ifndef TRANSITIONVIEW_H
#define TRANSITIONVIEW_H

#include "moveable.h"
#include "objs/transition.h"

class PW_PUBLIC ImmediateTransitionView : public Moveable
{
public:
    ImmediateTransitionView(PetriWidget *pWidget, spnp::Transition* transition);
    ~ImmediateTransitionView();

    enum { Type = UserType + 2 };

    int type() const override { return Type; }

    QPainterPath shape() const override;
    virtual std::string getTypeName() const;
protected:
    virtual void paintDraw(QPainter *painter) override;
    spnp::Transition* transition;
};

#endif // TRANSITION_H
