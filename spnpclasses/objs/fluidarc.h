#ifndef FLUIDARC_H
#define FLUIDARC_H

#include "objs/arc.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC FluidArc : public Arc
{
public:
    FluidArc();
    virtual ~FluidArc();

    /*virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);*/

private:
    virtual std::string getClassNodeName();
};
}
#endif // FLUIDARC_H
