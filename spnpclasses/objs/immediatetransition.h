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
    ImmediateTransition(std::string name, std::string priority, Label *label=nullptr, int x=0, int y=0);
    virtual ~ImmediateTransition();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getPriority() const;
    void setPriority(std::string p);

    std::string getGuard() const;
    void setGuard(std::string g);

    ProbabilityType getProbType() const;
    void setProbType(ProbabilityType t);

    bool isVertical();
    void setVertical(bool v);

protected:
    std::string priority;
    std::string guard;
    ProbabilityType probType;
    Label* label;

    bool vertical;

private:
    virtual std::string getClassNodeName();


};
}
#endif // TRANSITION_H
