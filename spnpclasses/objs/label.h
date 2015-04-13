#ifndef LABEL_H
#define LABEL_H

#include "abstractvisualdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Label : public AbstractVisualData
{
public:
    Label();
    Label(int id, std::string text, int x=0, int y=0);
    virtual ~Label();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

private:
    virtual std::string getClassNodeName();
    std::string text;
};
}
#endif // LABEL_H
