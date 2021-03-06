#include "fluidplace.h"

spnp::FluidPlace::FluidPlace():Place()
{
    this->boundValue = "";
    this->breakValue = "";
}

spnp::FluidPlace::~FluidPlace()
{

}

spnp::FluidPlace::FluidPlace(std::string name, std::string tokens, spnp::Label *label,
                             std::string boundValue, std::string breakValue, int x, int y)
    :Place(name, tokens, label, x, y)
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

std::string spnp::FluidPlace::getBoundValue()
{
    return this->boundValue;
}

std::string spnp::FluidPlace::getBreakValue()
{
    return this->breakValue;
}

void spnp::FluidPlace::setBoundValue(std::string v)
{
    this->boundValue = v;
}

void spnp::FluidPlace::setBreakValue(std::string v)
{
    this->breakValue = v;
}

std::string spnp::FluidPlace::c_str(IData *data) const
{
    (void)data;
    std::stringstream ss;

    ss << "fplace(\"" << getName() << "\");\n";
    if(this->tokens.compare("0")!=0)
    {
        ss<< "finit(\"" << getName() << "\"," << this->tokens << ");\n";
    }

    if(this->boundValue.compare("") != 0)
    {
        ss << "fbound(\"" << getName() << "\", "<< this->boundValue << ");\n";
    }

    if(this->breakValue.compare("") != 0)
    {
        ss << "fbreak(\"" << getName() << "\", "<< this->breakValue << ");\n";
    }
    return ss.str();
}

std::string spnp::FluidPlace::getClassNodeName()
{
    return "fluid_place";
}
