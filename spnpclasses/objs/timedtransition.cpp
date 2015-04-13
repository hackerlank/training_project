#include "timedtransition.h"

spnp::TimedTransition::TimedTransition():Transition()
{
    this->rate = "0.25";
    this->distribution = Distribution::Exponential;
    this->distValue = "";
    this->policy = Policy::PreemptiveRepeatDifferent;
    this->affected = Affected::PRS;
}

spnp::TimedTransition::TimedTransition(int id, std::string priority, std::string rate,
                                       Distribution distribution, std::string distValue,
                                       Policy policy, Affected affected, int x, int y)
    :Transition(id, priority, x, y)
{
    this->rate = rate;
    this->distribution = distribution;
    this->distValue = distValue;
    this->policy = policy;
    this->affected = affected;
}

spnp::TimedTransition::~TimedTransition()
{

}

XMLNode *spnp::TimedTransition::toXML()
{
    XMLNode* node = AbstractVisualData::toXML();
    node->setAttribute("rate", this->rate);
    node->setAttribute("dist_value", this->distValue);
    node->setAttribute("dist", static_cast<int>(this->distribution));

    return node;
}

void spnp::TimedTransition::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->rate = xml->getAttributeS("rate");
    this->distValue= xml->getAttributeS("dist_value");
    this->distribution = static_cast<Distribution>(xml->getAttributeI("dist"));
}

std::string spnp::TimedTransition::getClassNodeName()
{
    return "timed_transition";
}
