#include "transition.h"

spnp::Transition::Transition():AbstractVisualData()
{
    this->priority = "1";
    this->label = new Label();
}

spnp::Transition::Transition(int id, std::string name,
                             std::string value, Label *label, int x, int y):AbstractVisualData(id, name, x, y)
{
    this->priority = value;
    if(label==nullptr)
        this->label = label;
    else
        this->label = new Label();
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

    node->addChild(this->label->toXML());

    return node;
}

void spnp::Transition::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->priority = xml->getAttributeS("priority");
    this->guard = xml->getAttributeS("guard");
    this->probType = static_cast<ProbabilityType>(xml->getAttributeI("prob"));

    if(this->label !=nullptr)
        delete this->label;
    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

std::string spnp::Transition::getValue() const
{
    return this->priority;
}

std::string spnp::Transition::getClassNodeName()
{
    return "transition";
}
