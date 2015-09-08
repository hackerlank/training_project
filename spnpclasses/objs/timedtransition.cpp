#include "timedtransition.h"

spnp::TimedTransition::TimedTransition():Transition()
{
    this->rate = "0.25";
    this->distribution = Distribution::Exponential;
    this->distValue = "";
    this->policy = Policy::PreemptiveRepeatDifferent;
    this->affected = Affected::PRS;
    this->label = new Label();
}

spnp::TimedTransition::TimedTransition(std::string name, std::string priority, Label *label, std::string rate,
                                       Distribution distribution, std::string distValue,
                                       Policy policy, Affected affected, int x, int y)
    :Transition(name, priority, label, x, y)
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
    XMLNode* node = Transition::toXML();
    node->setAttribute("rate", this->rate);
    node->setAttribute("dist_value", this->distValue);
    node->setAttribute("dist", static_cast<int>(this->distribution));

    return node;
}

void spnp::TimedTransition::fromXML(XMLNode *xml)
{
    Transition::fromXML(xml);
    this->rate = xml->getAttributeS("rate");
    this->distValue= xml->getAttributeS("dist_value");
    this->distribution = static_cast<Distribution>(xml->getAttributeI("dist"));
}

std::string spnp::TimedTransition::getClassNodeName()
{
    return "timed_transition";
}
