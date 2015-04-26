#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include "moveable.h"

class PETRIWIDGET_PUBLIC PlaceView : public Moveable
{
public:
    PlaceView(PetriWidget *pWidget);
    ~PlaceView();

    enum { Type = UserType + 1 };

    int type() const override { return Type; }

    QPainterPath shape() const override;

protected:
    virtual void paintDraw(QPainter *painter) override;
};

#endif // PLACEVIEW_H
