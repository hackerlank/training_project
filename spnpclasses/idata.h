#ifndef IDATA_H
#define IDATA_H

#include "spnpclasses_global.h"
#include "xmlparser.h"
#include <sstream>

namespace spnp
{
    class SPNPCLASSES_PUBLIC IData
    {
    public:
        IData(){}
        virtual ~IData() {}

        virtual XMLNode* toXML()=0;
        virtual void fromXML(XMLNode *xml)=0;

        virtual std::string getName() const { return this->name; }
        virtual void setName(std::string name) { this->name = name; }

        virtual std::string c_str(IData* data=nullptr) const = 0;

        std::string id;
    protected:
        std::string name;
    };
}

#endif // IDATA_H
