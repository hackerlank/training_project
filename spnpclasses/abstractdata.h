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
        AbstractData(int id, std::string name);
        virtual ~AbstractData();

        virtual XMLNode* toXML();
        virtual void fromXML(XMLNode *xml);
    private:
        virtual std::string getClassNodeName()=0;
    };
}

#endif // ABSTRACTDATA_H
