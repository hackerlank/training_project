#include "labelview.h"

LabelView::LabelView(spnp::Label *label)
{
    this->label = label;
}

LabelView::~LabelView()
{

}

spnp::Label LabelView::getLabel() const
{
    return this->label;
}

