#include "outputfunction.h"

spnp::OutputFunction::OutputFunction(OutputFunction::TYPE type, std::string objId, std::string option):AbstractData()
{
    this->objId = objId;
    this->option = option;
    this->type = type;
}

spnp::OutputFunction::~OutputFunction()
{

}

XMLNode *spnp::OutputFunction::toXML()
{
    XMLNode* n = AbstractData::toXML();
    n->setAttribute("object_id", this->objId);
    n->setAttribute("option", this->option);
    n->setAttribute("type",static_cast<int>(this->type));

    return n;
}

void spnp::OutputFunction::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->objId = xml->getAttributeS("object_id");
    this->option = xml->getAttributeS("option");
    this->type = static_cast<OutputFunction::TYPE>(xml->getAttributeI("type"));
}

std::string spnp::OutputFunction::c_str(spnp::IData *data) const
{
    (void)data;
}

std::string spnp::OutputFunction::getClassNodeName()
{
    return "output_funcion";
}
