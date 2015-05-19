#include "labelview.h"

LabelView::LabelView(AbstractMoveable* m):QGraphicsSimpleTextItem(m)
{
    this->label = new spnp::Label();
    this->setFlags(ItemIsMovable | ItemIgnoresTransformations);
}

LabelView::~LabelView()
{

}

spnp::Label* LabelView::getLabel() const
{
    return this->label;
}

void LabelView::setText(std::string text)
{
    this->label->setName(text);
    QGraphicsSimpleTextItem::setText(QString::fromStdString(text));
}

AbstractMoveable::MoveableTypes LabelView::getTypeName() const
{
    return AbstractMoveable::label;
}

void LabelView::itemMoved(QPointF point)
{
    this->label->x = point.x();
    this->label->y = point.y();
}
