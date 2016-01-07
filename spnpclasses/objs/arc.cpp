#include "arc.h"

spnp::Arc::Arc():AbstractData()
{
    this->place = -1;
    this->transition = -1;
    this->fromPlaceToTransition = false;
    this->multiplicity = 1.;
    this->isFluid = false;
    this->isInhibitor = false;
}

spnp::Arc::Arc(std::string name, std::string place,
               std::string transition, bool fromPlaceToTransition,
               double multiplicity, bool isFluid, bool isInhibitor):AbstractData(name)
{
    this->place = place;
    this->transition = transition;
    this->fromPlaceToTransition = fromPlaceToTransition;
    this->multiplicity = multiplicity;
    this->isFluid = isFluid;
    this->isInhibitor = isInhibitor;
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
    node->setAttribute("fluid", this->isFluid);
    node->setAttribute("inhibitor", this->isInhibitor);
    return node;
}

void spnp::Arc::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->place = xml->getAttributeI("place");
    this->transition = xml->getAttributeI("transition");
    this->fromPlaceToTransition = xml->getAttributeB("ptot");
    this->isFluid = xml->getAttributeB("fluid");
    this->isInhibitor = xml->getAttributeB("inhibitor");
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

double spnp::Arc::getMultiplicity() const
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

void spnp::Arc::setMultiplicity(const double m)
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

std::string spnp::Arc::c_str() const
{
    throw;
}

std::string spnp::Arc::getClassNodeName()
{
    return "arc";
}
