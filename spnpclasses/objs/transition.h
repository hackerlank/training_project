#ifndef TRANSITION_H
#define TRANSITION_H

#include "abstractvisualdata.h"
#include "objs/label.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Transition : public AbstractVisualData
{
public:
    enum ProbabilityType
    {
        CONSTANT,
        PLACE_DEPENDENT,
        FUNCTION
    };

    Transition();
    Transition(std::string name, std::string priority, Label *label=nullptr, int x=0, int y=0);
    virtual ~Transition();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getValue() const;
protected:
    std::string priority;
    std::string guard;
    ProbabilityType probType;
    Label* label;

    //fazer
    bool isVertical;

private:
    virtual std::string getClassNodeName();


};
}
#endif // TRANSITION_H
