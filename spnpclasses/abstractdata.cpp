#include "abstractdata.h"

spnp::AbstractData::AbstractData()
{
    this->id = -1;
    this->name = "ad";
}

spnp::AbstractData::AbstractData(int id, std::string name)
{
    this->id = id;
    this->name = name;
}

spnp::AbstractData::~AbstractData()
{

}

XMLNode *spnp::AbstractData::toXML()
{
    XMLNode* node = new XMLNode(this->getClassNodeName());
    node->setAttribute("id", this->id);
    node->setAttribute("name", this->name);

    return node;
}

void spnp::AbstractData::fromXML(XMLNode *xml)
{
    this->id = xml->getAttributeI("id");
    this->name = xml->getAttributeS("name");
}
