#ifndef TIMEDTRANSITION_H
#define TIMEDTRANSITION_H

#include "objs/transition.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC TimedTransition : public Transition
{
public:
    enum Distribution
    {
        Exponential,
        Constant,
        Uniform,
        TruncatedNormal,
        Weibull,
        LogNormal,
        Geometric,
        Erlang,
        Normal,
        HyperExponencial
    };

    enum Policy
    {
        PreemptiveRepeatIdentical,  //pri
        PreemptiveRepeatDifferent,  //prd
        PreemptiveResume            //prr
    };

    enum Affected
    {
        PRI,
        PRS,
        PRD
    };

    TimedTransition();
    TimedTransition(int id, std::string name,
                    std::string priority, std::string rate="0.25",
                    Distribution distribution = Distribution::Exponential,
                    std::string distValue="", Policy policy = Policy::PreemptiveRepeatDifferent,
                    Affected affected = Affected::PRS, int x=0, int y=0);
    virtual ~TimedTransition();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

private:
    std::string rate;
    Distribution distribution;
    std::string distValue;
    Policy policy;
    Affected affected;
    virtual std::string getClassNodeName();

};
}

#endif // TIMEDTRANSITION_H
