#include "timedtransition.h"

spnp::TimedTransition::TimedTransition():ImmediateTransition()
{
    this->value = "0.25";
    this->distribution = Distribution::Exponential;
    this->distValue = "";
    this->policy = Policy::PreemptiveRepeatDifferent;
    this->affected = Affected::PRS;
    this->label = new Label();
}

spnp::TimedTransition::TimedTransition(std::string name, std::string priority, std::string guard,
                                       ProbabilityType probType, std::string value,
                                       Label *label,
                                       Distribution distribution, std::string distValue,
                                       Policy policy, Affected affected, int x, int y)
    :ImmediateTransition(name, priority, guard, probType, value, label, x, y)
{
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
    XMLNode* node = ImmediateTransition::toXML();
    node->setAttribute("dist_value", this->distValue);
    node->setAttribute("dist", static_cast<int>(this->distribution));
    node->setAttribute("policy", static_cast<int>(this->policy));
    node->setAttribute("affected", static_cast<int>(this->affected));

    return node;
}

void spnp::TimedTransition::fromXML(XMLNode *xml)
{
    ImmediateTransition::fromXML(xml);
    this->distValue= xml->getAttributeS("dist_value");
    this->distribution = static_cast<Distribution>(xml->getAttributeI("dist"));
    this->policy = static_cast<Policy>(xml->getAttributeI("policy"));
    this->affected = static_cast<Affected>(xml->getAttributeI("affected"));
}

void spnp::TimedTransition::setDistribution(spnp::TimedTransition::Distribution d)
{
    this->distribution = d;
}

void spnp::TimedTransition::setDistributionValue(std::string dv)
{
    this->distValue = dv;
}

void spnp::TimedTransition::setPolicy(spnp::TimedTransition::Policy p)
{
    this->policy = p;
}

void spnp::TimedTransition::setAffected(spnp::TimedTransition::Affected a)
{
    this->affected = a;
}

spnp::TimedTransition::Distribution spnp::TimedTransition::getDistribution()
{
    return this->distribution;
}

std::string spnp::TimedTransition::getDistributionValue()
{
    return this->distValue;
}

spnp::TimedTransition::Policy spnp::TimedTransition::getPolicy()
{
    return this->policy;
}

spnp::TimedTransition::Affected spnp::TimedTransition::getAffected()
{
    return this->affected;
}

std::string spnp::TimedTransition::c_str() const
{
    std::stringstream ss;



    return ss.str();
}

std::string spnp::TimedTransition::getClassNodeName()
{
    return "timed_transition";
}
