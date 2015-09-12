#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include "spnpclasses_global.h"
#include "idata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC AbstractData : public IData
{
public:
    AbstractData();
    AbstractData(std::string name);
    virtual ~AbstractData();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);
protected:
    virtual std::string getClassNodeName()=0;
private:
    void createID();
};
}

#endif // ABSTRACTDATA_H
