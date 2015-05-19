#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include "view/abstractlabeledmoveable.h"
#include "objs/place.h"
class PW_PUBLIC PlaceView : public AbstractLabeledMoveable
{
public:
    PlaceView(PetriWidget *pWidget, spnp::Place* place);
    ~PlaceView();

    enum { Type = UserType + 1 };

    int type() const override { return Type; }

    QPainterPath shape() const override;
    virtual MoveableTypes getTypeName() const;
    spnp::Place* getPlace() const;

    std::string getName() const;
    virtual void setName(std::string txt) override;

    double getValue() const;
    void setValue(double d);
protected:
    virtual void paintDraw(QPainter *painter) override;

    virtual void itemMoved(QPointF point);

    spnp::Place* place;
};

#endif // PLACEVIEW_H
