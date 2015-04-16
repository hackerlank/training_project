#ifndef TRANSITION_H
#define TRANSITION_H

#include "abstractvisualdata.h"

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
    Transition(int id, std::string name, std::string priority, int x=0, int y=0);
    virtual ~Transition();
    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    std::string getValue() const;
protected:
    std::string priority;
    std::string guard;
    ProbabilityType probType;

    //fazer
    bool isVertical;

private:
    virtual std::string getClassNodeName();


};
}
#endif // TRANSITION_H
