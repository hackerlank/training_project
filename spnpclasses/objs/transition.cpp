#include "transition.h"

spnp::Transition::Transition():AbstractVisualData()
{
    this->priority = "1";
}

spnp::Transition::Transition(int id, std::string value, int x, int y):AbstractVisualData(id, x, y)
{
    this->priority = value;
}

spnp::Transition::~Transition()
{

}

XMLNode *spnp::Transition::toXML()
{
    XMLNode* node = AbstractVisualData::toXML();
    node->setAttribute("priority", this->priority);
    node->setAttribute("guard", this->guard);
    node->setAttribute("prob", static_cast<int>(this->probType));

    return node;
}

void spnp::Transition::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->priority = xml->getAttributeS("priority");
    this->guard = xml->getAttributeS("guard");
    this->probType = static_cast<ProbabilityType>(xml->getAttributeI("prob"));
}

std::string spnp::Transition::getValue() const
{
    return this->priority;
}

std::string spnp::Transition::getClassNodeName()
{
    return "transition";
}
