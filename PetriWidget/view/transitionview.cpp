#include "transitionview.h"

#include <QPainter>

TransitionView::TransitionView(PetriWidget *pWidget):Moveable(pWidget)
{
    this->_H_ = 20;
    this->_W_ = 6;
}

TransitionView::~TransitionView()
{

}

QPainterPath TransitionView::shape() const
{
    QPainterPath path;
    path.addRect(-_W_/2, -_H_/2, _W_, _H_);
    return path;
}

std::string TransitionView::getTypeName() const
{
    return "timed_trans";
}

void TransitionView::paintDraw(QPainter *painter)
{
    QRect r(-_W_/2, -_H_/2, _W_, _H_);
    painter->fillRect(r, QBrush(this->color_black));
}
