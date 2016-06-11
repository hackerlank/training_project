#ifndef PLACE_H
#define PLACE_H

#include "label.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Place : public AbstractVisualData
{
public:
    Place();
    Place(int id, std::string name, double tokens=0., Label* label = nullptr, int x=0, int y=0);
    virtual ~Place();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    double getTokens() const;
    void setToken(const double d);
    Label* getLabel() const;
private:
    double tokens;

    Label* label;
    virtual std::string getClassNodeName();
};
}

#endif // PLACE_H
