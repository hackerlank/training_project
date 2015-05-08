#include "immediatetransitionview.h"

#include <QPainter>

ImmediateTransitionView::ImmediateTransitionView(PetriWidget *pWidget, spnp::Transition *transition):Moveable(pWidget)
{
    this->_H_ = 20;
    this->_W_ = 6;
    this->transition = transition;
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

std::string ImmediateTransitionView::getTypeName() const
{
    return "timed_trans";
}

void ImmediateTransitionView::paintDraw(QPainter *painter)
{
    QRect r(-_W_/2, -_H_/2, _W_, _H_);
    painter->fillRect(r, QBrush(this->color_black));
}
