#include "immediatetransition.h"

spnp::ImmediateTransition::ImmediateTransition():AbstractVisualData()
{
    this->priority = "1";
    this->guard = "";
    this->probType = ProbabilityType::CONSTANT;
    this->value = "0.789";
    this->label = new Label();
}

spnp::ImmediateTransition::ImmediateTransition(std::string name,
                             std::string priority, std::string guard,
                             ProbabilityType probType, std::string value, Label *label,
                             int x, int y)
    :AbstractVisualData(name, x, y)
{
    this->priority = priority;
    this->guard = guard;
    this->probType = probType;
    this->value = value;

    if(label==nullptr)
        this->label = label;
    else
        this->label = new Label();
}

spnp::ImmediateTransition::~ImmediateTransition()
{
    //delete this->label;
}

XMLNode *spnp::ImmediateTransition::toXML()
{
    XMLNode* node = AbstractVisualData::toXML();
    node->setAttribute("priority", this->priority);
    node->setAttribute("guard", this->guard);
    node->setAttribute("prob", static_cast<int>(this->probType));
    node->setAttribute("value", this->value);
    node->setAttribute("vertical", this->vertical);

    node->addChild(this->label->toXML());

    return node;
}

void spnp::ImmediateTransition::fromXML(XMLNode *xml)
{
    AbstractVisualData::fromXML(xml);
    this->priority = xml->getAttributeS("priority");
    this->guard = xml->getAttributeS("guard");
    this->probType = static_cast<ProbabilityType>(xml->getAttributeI("prob"));
    this->value = xml->getAttributeS("value");
    this->vertical = xml->getAttributeB("vertical");

    if(this->label !=nullptr)
        delete this->label;
    this->label = new Label();
    this->label->fromXML(xml->getChildAt(0));
}

std::string spnp::ImmediateTransition::getPriority() const
{
    return this->priority;
}

void spnp::ImmediateTransition::setPriority(std::string p)
{
    this->priority = p;
}

std::string spnp::ImmediateTransition::getGuard() const
{
    return this->guard;
}

void spnp::ImmediateTransition::setGuard(std::string g)
{
    this->guard = g;
}

spnp::ImmediateTransition::ProbabilityType spnp::ImmediateTransition::getProbType() const
{
    return this->probType;
}

void spnp::ImmediateTransition::setProbType(spnp::ImmediateTransition::ProbabilityType t)
{
    this->probType = t;
}

std::string spnp::ImmediateTransition::getValue() const
{
    return this->value;
}

void spnp::ImmediateTransition::setValue(std::string v)
{
    this->value = v;
}

bool spnp::ImmediateTransition::isVertical()
{
    return this->vertical;
}

void spnp::ImmediateTransition::setVertical(bool v)
{
    this->vertical = v;
}

std::string spnp::ImmediateTransition::getClassNodeName()
{
    return "transition";
}
