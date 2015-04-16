#include "place.h"

spnp::Place::Place():AbstractVisualData()
{
    this->tokens = 1.;
    this->label = new Label();
}

spnp::Place::Place(int id, std::string name, double tokens, Label *label, int x, int y)
    :AbstractVisualData(id, name, x, y)
{
    this->tokens = tokens;
    if(label != nullptr)
        this->label = label;
    else
        this->label = new Label();
}

spnp::Place::~Place()
{
    delete this->label;
}

XMLNode *spnp::Place::toXML()
{
    XMLNode* n = AbstractVisualData::toXML();
    n->setAttribute("tokens", this->tokens);

    n->addChild(this->label->toXML());

    return n;
}

void spnp::Place::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->tokens = xml->getAttributeD("tokens");

    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

double spnp::Place::getTokensOrInitValue() const
{
    return this->tokens;
}

spnp::Label *spnp::Place::getLabel() const
{
    return this->label;
}

std::string spnp::Place::getClassNodeName()
{
    return "place";
}
