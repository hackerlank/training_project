#include "label.h"

spnp::Label::Label():AbstractVisualData()
{
}

spnp::Label::Label(std::string name, int x, int y):AbstractVisualData(name, x, y)
{
}

spnp::Label::~Label()
{

}

XMLNode *spnp::Label::toXML()
{
    XMLNode* n = AbstractVisualData::toXML();

    return n;
}

void spnp::Label::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
}

std::string spnp::Label::getClassNodeName()
{
    return "label";
}
