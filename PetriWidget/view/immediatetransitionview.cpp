#include "immediatetransitionview.h"

#include <QPainter>

ImmediateTransitionView::ImmediateTransitionView(PetriWidget *pWidget, spnp::Transition *transition):AbstractLabeledMoveable(pWidget)
{
    this->_H_ = 20;
    this->_W_ = 6;
    this->transition = transition;

    this->setName(this->transition->getName());
}

ImmediateTransitionView::~ImmediateTransitionView()
{
    delete this->transition;
}

QPainterPath ImmediateTransitionView::shape() const
{
    QPainterPath path;
    path.addRect(-_W_/2, -_H_/2, _W_, _H_);
    return path;
}

AbstractMoveable::MoveableTypes ImmediateTransitionView::getTypeName() const
{
    return MoveableTypes::itrans;
}

std::string ImmediateTransitionView::getName() const
{
    return this->transition->getName();
}

void ImmediateTransitionView::setName(std::string name)
{
    AbstractLabeledMoveable::setName(name);
    this->transition->setName(name);
}

void ImmediateTransitionView::paintDraw(QPainter *painter)
{
    QRect r(-_W_/2, -_H_/2, _W_, _H_);
    painter->fillRect(r, QBrush(this->getBrushColor()));
}

void ImmediateTransitionView::itemMoved(QPointF point)
{
    this->transition->x = point.x();
    this->transition->y = point.y();
}
