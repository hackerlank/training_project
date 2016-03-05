#ifndef OUTPUTOPTION_H
#define OUTPUTOPTION_H

#include "abstractdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC OutputOption : public AbstractData
{
public:
    OutputOption();
    OutputOption(std::string name);
    ~OutputOption();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    virtual std::string c_str(IData* data=nullptr) const;
protected:
    virtual std::string getClassNodeName();
};
}

#endif // OUTPUTOPTION_H
