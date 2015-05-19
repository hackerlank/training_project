#include "placeview.h"

#include <QPainter>

PlaceView::PlaceView(PetriWidget *pWidget, spnp::Place *place):AbstractLabeledMoveable(pWidget)
{
    this->place = place;
    this->setName(place->getName());
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

AbstractMoveable::MoveableTypes PlaceView::getTypeName() const
{
    return MoveableTypes::place;
}

spnp::Place *PlaceView::getPlace() const
{
    return this->place;
}

std::string PlaceView::getName() const
{
    return this->place->getName();
}

void PlaceView::setName(std::string name)
{
    AbstractLabeledMoveable::setName(name);
    this->place->setName(name);
}

double PlaceView::getValue() const
{
    return this->place->getTokens();
}

void PlaceView::setValue(double d)
{
    this->place->setToken(d);
}

void PlaceView::itemMoved(QPointF point)
{
    this->place->x = point.x();
    this->place->y = point.y();
}

void PlaceView::paintDraw(QPainter *painter)
{
    painter->drawEllipse(-_H_/2, -_H_/2, _H_, _H_);
}
