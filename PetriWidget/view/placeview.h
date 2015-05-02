#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include "moveable.h"

class PW_PUBLIC PlaceView : public Moveable
{
public:
    PlaceView(PetriWidget *pWidget);
    ~PlaceView();

    enum { Type = UserType + 1 };

    int type() const override { return Type; }

    QPainterPath shape() const override;
    virtual std::string getTypeName() const;
protected:
    virtual void paintDraw(QPainter *painter) override;
};

#endif // PLACEVIEW_H
