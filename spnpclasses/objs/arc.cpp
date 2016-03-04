#include "arc.h"

#include "objs/net.h"

spnp::Arc::Arc():AbstractData()
{
    this->place = -1;
    this->transition = -1;
    this->fromPlaceToTransition = false;
    this->multiplicity = "1";
    this->isFluid = false;
    this->isInhibitor = false;
}

spnp::Arc::Arc(std::string name, std::string place,
               std::string transition, bool fromPlaceToTransition,
               std::string multiplicity, bool isFluid, bool isInhibitor, bool isConstant):AbstractData(name)
{
    this->place = place;
    this->transition = transition;
    this->fromPlaceToTransition = fromPlaceToTransition;
    this->multiplicity = multiplicity;
    this->isFluid = isFluid;
    this->isInhibitor = isInhibitor;
    this->isConstant = isConstant;
}

spnp::Arc::~Arc()
{

}

XMLNode *spnp::Arc::toXML()
{
    XMLNode* node = AbstractData::toXML();
    node->setAttribute("place", this->place);
    node->setAttribute("transition", this->transition);
    node->setAttribute("ptot", this->fromPlaceToTransition);
    node->setAttribute("multiplicity", this->multiplicity);
    node->setAttribute("fluid", this->isFluid);
    node->setAttribute("inhibitor", this->isInhibitor);
    node->setAttribute("const", this->isConstant);
    return node;
}

void spnp::Arc::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->place = xml->getAttributeS("place");
    this->transition = xml->getAttributeS("transition");
    this->fromPlaceToTransition = xml->getAttributeB("ptot");
    this->multiplicity = xml->getAttributeS("multiplicity");
    this->isFluid = xml->getAttributeB("fluid");
    this->isInhibitor = xml->getAttributeB("inhibitor");
    this->isConstant = xml->getAttributeB("const");
}

std::string spnp::Arc::getPlaceId() const
{
    return this->place;
}

std::string spnp::Arc::getTransitionId() const
{
    return this->transition;
}

bool spnp::Arc::getFromPlaceToTransition() const
{
    return this->fromPlaceToTransition;
}

std::string spnp::Arc::getMultiplicity() const
{
    return this->multiplicity;
}

bool spnp::Arc::getIsFluid() const
{
    return this->isFluid;
}

bool spnp::Arc::getIsInhibitor() const
{
    return this->isInhibitor;
}

bool spnp::Arc::getIsConstant() const
{
    return this->isConstant;
}

void spnp::Arc::setPlace(const std::string id)
{
    this->place = id;
}

void spnp::Arc::setTransition(const std::string id)
{
    this->transition = id;
}

void spnp::Arc::setFromPlaceToTransition(const bool b)
{
    this->fromPlaceToTransition = b;
}

void spnp::Arc::setMultiplicity(const std::string m)
{
    this->multiplicity = m;
}

void spnp::Arc::setIsFluid(const bool b)
{
    this->isFluid = b;
}

void spnp::Arc::setIsInhibitor(const bool b)
{
    this->isInhibitor = b;
}

void spnp::Arc::setIsConstant(const bool b)
{
    this->isConstant = b;
}

std::string spnp::Arc::c_str(IData *data) const
{
    (void)data;
    std::stringstream ss;

    spnp::Net* net = static_cast<Net*>(data);

    if(this->fromPlaceToTransition)
    {
        if(this->multiplicity.compare("1")!=0)
            ss << "oarc(\"" << net->getTransition(transition)->getName() << "\", \"" << net->getPlace(place)->getName() << "\");\n";
        else
            ss << "moarc(\"" << net->getTransition(transition)->getName() << "\", \"" << net->getPlace(place)->getName() << "\", " << this->multiplicity <<");\n";

    }
    else
    {
        if(this->multiplicity.compare("1")!=0)
            ss << "iarc(\"" << net->getTransition(transition)->getName() << "\", \"" << net->getPlace(place)->getName() << "\");\n";
        else
            ss << "miarc(\"" << net->getTransition(transition)->getName() << "\", \"" << net->getPlace(place)->getName() << "\", " << this->multiplicity <<");\n";
    }

    return ss.str();
}

std::string spnp::Arc::getClassNodeName()
{
    return "arc";
}
