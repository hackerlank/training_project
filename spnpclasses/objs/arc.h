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
        bool fromPlaceToTransition=false, std::string multiplicity="1", bool isFluid=false, bool isInhibitor=false,
        bool isConstant=true);
    virtual ~Arc();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getPlaceId() const;
    std::string getTransitionId() const;
    bool getFromPlaceToTransition() const;
    std::string getMultiplicity() const;
    bool getIsFluid() const;
    bool getIsInhibitor() const;
    bool getIsConstant() const;
    void setPlace(const std::string id);
    void setTransition(const std::string id);
    void setFromPlaceToTransition(const bool b);
    void setMultiplicity(const std::string m);
    void setIsFluid(const bool b);
    void setIsInhibitor(const bool b);
    void setIsConstant(const bool b);

    virtual std::string c_str(IData* data=nullptr) const;

    void operator=(const Arc &a);
    virtual std::string getClassNodeName();
private:
    std::string place;
    std::string transition;
    bool fromPlaceToTransition;
    std::string multiplicity;

    bool isConstant;

    bool isFluid;
    bool isInhibitor;
};
}

#endif // ARC_H
