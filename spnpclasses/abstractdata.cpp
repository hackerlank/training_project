#include "abstractdata.h"

spnp::AbstractData::AbstractData()
{
    this->id = -1;
}

spnp::AbstractData::AbstractData(int id)
{
    this->id = id;
}

spnp::AbstractData::~AbstractData()
{

}

XMLNode *spnp::AbstractData::toXML()
{
    XMLNode* node = new XMLNode(this->getClassNodeName());
    node->setAttribute("id", this->id);

    return node;
}

void spnp::AbstractData::fromXML(XMLNode *xml)
{
    this->id = xml->getAttributeI("id");
}
