#include "arc.h"

spnp::Arc::Arc():AbstractData()
{
    this->place = -1;
    this->transition = -1;
    this->fromPlaceToTransition = false;
    this->multiplicity = 1.;
}

spnp::Arc::Arc(int id, std::string name, int place,
               int transition, bool fromPlaceToTransition,
               double multiplicity):AbstractData(id, name)
{
    this->place = place;
    this->transition = transition;
    this->fromPlaceToTransition = fromPlaceToTransition;
    this->multiplicity = multiplicity;
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
    return node;
}

void spnp::Arc::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->place = xml->getAttributeI("place");
    this->transition = xml->getAttributeI("transition");
    this->fromPlaceToTransition = xml->getAttributeB("ptot");
}

int spnp::Arc::getPlaceId() const
{
    return this->place;
}

int spnp::Arc::getTransitionId() const
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

void spnp::Arc::setPlace(const int id)
{
    this->place = id;
}

void spnp::Arc::setTransition(const int id)
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

std::string spnp::Arc::getClassNodeName()
{
    return "arc";
}
