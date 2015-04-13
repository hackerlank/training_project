#include "label.h"

spnp::Label::Label():AbstractVisualData()
{
    this->text = "name";
}

spnp::Label::Label(int id, std::string text, int x, int y):AbstractVisualData(id, x, y)
{
    this->text = text;
}

spnp::Label::~Label()
{

}

XMLNode *spnp::Label::toXML()
{
    XMLNode* n = AbstractVisualData::toXML();
    n->setAttribute("text", this->text);

    return n;
}

void spnp::Label::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->text = xml->getAttributeS("text");
}

std::string spnp::Label::getClassNodeName()
{
    return "label";
}
