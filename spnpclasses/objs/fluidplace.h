#ifndef FLUIDPLACE_H
#define FLUIDPLACE_H

#include "objs/place.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC FluidPlace : public Place
{
public:
    FluidPlace();
    FluidPlace(std::string name, double tokens=0., Label* label = nullptr,
               std::string boundValue="", std::string breakValue="", int x=0, int y=0);
    virtual ~FluidPlace();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getBoundValue();
    std::string getBreakValue();
    void setBoundValue(std::string v);
    void setBreakValue(std::string v);

private:
    virtual std::string getClassNodeName();

    std::string boundValue;
    std::string breakValue;
};
}
#endif // FLUIDPLACE_H
