#include "place.h"

spnp::Place::Place():AbstractVisualData()
{
    this->tokens = "0";
    this->label = new Label();
}

spnp::Place::Place(std::string name, std::string tokens, Label *label, int x, int y)
    :AbstractVisualData(name, x, y)
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

    if(this->label != nullptr)
        delete this->label;

    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

std::string spnp::Place::getToken() const
{
    return this->tokens;
}

void spnp::Place::setToken(const std::string d)
{
    this->tokens = d;
}

spnp::Label *spnp::Place::getLabel() const
{
    return this->label;
}

std::string spnp::Place::c_str() const
{
    std::stringstream ss;
    ss << "place(\"" << getName() << "\");\n";
    if(this->tokens.compare("0")!=0)
    {
        ss<< "init(\"" << getName() << "\"," << this->tokens << ");\n";
    }
    return ss.str();
}

std::string spnp::Place::getClassNodeName()
{
    return "place";
}
