#include "placeview.h"

#include <QPainter>

PlaceView::PlaceView(PetriWidget *pWidget, spnp::Place *place):Moveable(pWidget)
{
    this->place = place;
}

PlaceView::~PlaceView()
{
    delete this->place;
}

QPainterPath PlaceView::shape() const
{
    QPainterPath path;
    path.addEllipse(-_H_/2, -_H_/2, _H_, _H_);
    return path;
}

std::string PlaceView::getTypeName() const
{
    return "place";
}

void PlaceView::paintDraw(QPainter *painter)
{
    painter->drawEllipse(-_H_/2, -_H_/2, _H_, _H_);
}
