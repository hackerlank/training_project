#include "outputoption.h"

spnp::OutputOption::OutputOption()
{
    this->name
}

spnp::OutputOption::OutputOption(std::string name)
    :AbstractData(name)
{

}

spnp::OutputOption::~OutputOption()
{

}

XMLNode *spnp::OutputOption::toXML()
{
    XMLNode* n = AbstractVisualData::toXML();
    n->setAttribute("tokens", this->tokens);

    n->addChild(this->label->toXML());

    return n;
}

void spnp::OutputOption::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->tokens = xml->getAttributeD("tokens");

    if(this->label != nullptr)
        delete this->label;

    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

std::string spnp::OutputOption::c_str(spnp::IData *data) const
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

std::string spnp::OutputOption::getClassNodeName()
{
    return "outputoption";
}
