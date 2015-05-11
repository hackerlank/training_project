#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include "moveable.h"
#include "objs/place.h"
class PW_PUBLIC PlaceView : public Moveable
{
public:
    PlaceView(PetriWidget *pWidget, spnp::Place* place);
    ~PlaceView();

    enum { Type = UserType + 1 };

    int type() const override { return Type; }

    QPainterPath shape() const override;
    virtual MoveableTypes getTypeName() const;
protected:
    virtual void paintDraw(QPainter *painter) override;
    spnp::Place* place;
};

#endif // PLACEVIEW_H
