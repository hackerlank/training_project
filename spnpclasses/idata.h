#ifndef IDATA_H
#define IDATA_H

#include "spnpclasses_global.h"
#include "xmlnode.h"

namespace spnp
{
    class SPNPCLASSES_PUBLIC IData
    {
    public:
        IData(){}
        virtual ~IData() {}

        virtual XMLNode* toXML()=0;
        virtual void fromXML(XMLNode *xml)=0;

        int id;
    };
}

#endif // IDATA_H
