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
        bool fromPlaceToTransition=false, double multiplicity=1., bool isFluid=false, bool isInhibitor=false);
    virtual ~Arc();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getPlaceId() const;
    std::string getTransitionId() const;
    bool getFromPlaceToTransition() const;
    double getMultiplicity() const;
    bool getIsFluid() const;
    bool getIsInhibitor() const;
    void setPlace(const std::string id);
    void setTransition(const std::string id);
    void setFromPlaceToTransition(const bool b);
    void setMultiplicity(const double m);
    void setIsFluid(const bool b);
    void setIsInhibitor(const bool b);

    virtual std::string c_str() const;

private:
    std::string place;
    std::string transition;
    bool fromPlaceToTransition;
    double multiplicity;

    virtual std::string getClassNodeName();

    bool isFluid;
    bool isInhibitor;
};
}

#endif // ARC_H
