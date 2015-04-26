#ifndef TRANSITIONVIEW_H
#define TRANSITIONVIEW_H

#include "moveable.h"

class PETRIWIDGET_PUBLIC TransitionView : public Moveable
{
public:
    TransitionView(PetriWidget *pWidget);
    ~TransitionView();

    enum { Type = UserType + 2 };

    int type() const override { return Type; }

    QPainterPath shape() const override;

protected:
    virtual void paintDraw(QPainter *painter) override;
};

#endif // TRANSITION_H
