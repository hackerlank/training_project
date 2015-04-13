#include "place.h"

spnp::Place::Place():AbstractVisualData()
{
    this->name = "a";
    this->tokens = 1.;
    this->label = new Label();
}

spnp::Place::Place(int id, std::string name, double tokens, Label *label, int x, int y):AbstractVisualData(id, x, y)
{
    this->name = name;
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
    n->setAttribute("name", this->name);

    n->addChild(this->label->toXML());

    return n;
}

void spnp::Place::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->tokens = xml->getAttributeD("tokens");
    this->name = xml->getAttributeS("name");

    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

double spnp::Place::getTokensOrInitValue() const
{
    return this->tokens;
}

std::string spnp::Place::getName() const
{
    return this->name;
}

spnp::Label *spnp::Place::getLabel() const
{
    return this->label;
}

std::string spnp::Place::getClassNodeName()
{
    return "place";
}
