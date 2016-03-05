#include "option.h"

spnp::Option::Option()
{

}

spnp::Option::Option(std::string name)
    :AbstractData(name)
{

}

spnp::Option::~Option()
{

}

XMLNode *spnp::Option::toXML()
{
    XMLNode* n = AbstractData::toXML();
    n->setAttribute("tokens", this->tokens);

    n->addChild(this->label->toXML());

    return n;
}

void spnp::Option::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->tokens = xml->getAttributeD("tokens");

    if(this->label != nullptr)
        delete this->label;

    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

std::string spnp::Option::c_str(spnp::IData *data) const
{
    (void)data;
    std::stringstream ss;
    ss << "place(\"" << getName() << "\");\n";
    if(this->tokens.compare("0")!=0)
    {
        ss<< "init(\"" << getName() << "\"," << this->tokens << ");\n";
    }
    return ss.str();
}

std::string spnp::Option::getClassNodeName()
{
    return "option";
}
