#ifndef ARC_H
#define ARC_H

#include "abstractvisualdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Arc : public AbstractData
{
public:
    Arc();
    Arc(std::string name, std::string place="", std::string transition="",
        bool fromPlaceToTransition=false, double multiplicity=1., bool isFluid=false);
    virtual ~Arc();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getPlaceId() const;
    std::string getTransitionId() const;
    bool getFromPlaceToTransition() const;
    double getMultiplicity() const;
    bool getIsFluid() const;
    void setPlace(const std::string id);
    void setTransition(const std::string id);
    void setFromPlaceToTransition(const bool b);
    void setMultiplicity(const double m);
    void setIsFluid(const bool b);

private:
    std::string place;
    std::string transition;
    bool fromPlaceToTransition;
    double multiplicity;

    virtual std::string getClassNodeName();

    bool isFluid;
};
}

#endif // ARC_H
