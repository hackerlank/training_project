#ifndef PLACE_H
#define PLACE_H

#include "label.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Place : public AbstractVisualData
{
public:
    Place();
    Place(std::string name, std::string tokens="0", Label* label = nullptr, int x=0, int y=0);
    virtual ~Place();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getToken() const;
    void setToken(const std::string d);
    Label* getLabel() const;
private:
    std::string tokens;

    Label* label;
    virtual std::string getClassNodeName();
};
}

#endif // PLACE_H
