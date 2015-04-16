#include "fluidplace.h"

spnp::FluidPlace::FluidPlace():Place()
{
    this->boundValue = "";
    this->breakValue = "";
}

spnp::FluidPlace::~FluidPlace()
{

}

spnp::FluidPlace::FluidPlace(int id, std::string name, double tokens, spnp::Label *label,
                             std::string boundValue, std::string breakValue, int x, int y)
    :Place(id, name, tokens, label, x, y)
{
    this->boundValue = boundValue;
    this->breakValue = breakValue;
}

XMLNode *spnp::FluidPlace::toXML()
{
    XMLNode* n = Place::toXML();
    n->setAttribute("bound", this->boundValue);
    n->setAttribute("break", this->breakValue);

    return n;
}

void spnp::FluidPlace::fromXML(XMLNode *xml)
{
    Place::fromXML(xml);
    this->boundValue = xml->getAttributeS("bound");
    this->breakValue = xml->getAttributeS("break");
}

std::string spnp::FluidPlace::getClassNodeName()
{
    return "fluid_place";
}
