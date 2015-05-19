#include "abstractlabeledmoveable.h"

AbstractLabeledMoveable::AbstractLabeledMoveable(PetriWidget *pWidget):AbstractMoveable(pWidget)
{
    this->label = new LabelView(this);
    this->setLabelPosition(QPoint(-this->_W_/2, this->_H_));
}

AbstractLabeledMoveable::~AbstractLabeledMoveable()
{

}

void AbstractLabeledMoveable::setName(std::string txt)
{
    this->label->setText(txt);
}

void AbstractLabeledMoveable::setLabelPosition(QPointF point)
{
    this->label->setPos(point);
}
