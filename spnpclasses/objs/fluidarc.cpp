#include "fluidarc.h"

spnp::FluidArc::FluidArc():Arc()
{

}

spnp::FluidArc::~FluidArc()
{

}
/*
XMLNode *spnp::FluidArc::toXML()
{
    XMLNode* node = Arc::toXML();

    return node;
}

void spnp::FluidArc::fromXML(XMLNode *xml)
{
    Arc::fromXML(xml);

}*/

std::string spnp::FluidArc::getClassNodeName()
{
    return "fluid_arc";
}
