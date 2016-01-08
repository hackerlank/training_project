#ifndef TRANSITION_H
#define TRANSITION_H

#include "abstractvisualdata.h"
#include "objs/label.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC ImmediateTransition : public AbstractVisualData
{
public:
    enum ProbabilityType
    {
        CONSTANT,
        PLACE_DEPENDENT,
        FUNCTION
    };

    ImmediateTransition();
    ImmediateTransition(std::string name, std::string priority, std::string guard = "",
                        ProbabilityType probType = ProbabilityType::CONSTANT,
                        std::string value = "0.789",
                        Label *label=nullptr, int x=0, int y=0);
    virtual ~ImmediateTransition();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getPriority() const;
    void setPriority(std::string p);

    std::string getGuard() const;
    void setGuard(std::string g);

    ProbabilityType getProbType() const;
    void setProbType(ProbabilityType t);

    std::string getValue() const;
    void setValue(std::string v);

    bool isVertical();
    void setVertical(bool v);

    std::string getPlaceId() const;
    void setPlaceId(std::string id);

    virtual std::string c_str(IData* data=nullptr) const;

protected:
    std::string priority;
    std::string guard;
    ProbabilityType probType;
    Label* label;

    std::string value;

    std::string placeId;

    bool vertical;

private:
    virtual std::string getClassNodeName();


};
}
#endif // TRANSITION_H
