#ifndef ARC_H
#define ARC_H

#include "abstractvisualdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Arc : public AbstractData
{
public:
    Arc();
    Arc(int id, int place=-1, int transition=-1, bool fromPlaceToTransition=false, double multiplicity=1.);
    virtual ~Arc();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    int getPlaceId() const;
    int getTransitionId() const;
    bool getFromPlaceToTransition() const;
    double getMultiplicity() const;

    void setPlace(const int id);
    void setTransition(const int id);
    void setFromPlaceToTransition(const bool b);
    void setMultiplicity(const double m);
private:
    int place;
    int transition;
    bool fromPlaceToTransition;
    double multiplicity;

    virtual std::string getClassNodeName();
};
}

#endif // ARC_H
