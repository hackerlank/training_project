#ifndef ABSTRACTVISUALDATA_H
#define ABSTRACTVISUALDATA_H

#include "abstractdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC AbstractVisualData : public AbstractData
{
public:
    AbstractVisualData();
    AbstractVisualData(std::string name, int x=0, int y=0);
    virtual ~AbstractVisualData();

    int x;
    int y;

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);
protected:
    virtual std::string getClassNodeName()=0;
};
}

#endif // ABSTRACTVISUALDATA_H
