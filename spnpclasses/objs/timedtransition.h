#ifndef TIMEDTRANSITION_H
#define TIMEDTRANSITION_H

#include "objs/immediatetransition.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC TimedTransition : public ImmediateTransition
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
    TimedTransition(std::string name,
                    std::string priority,
                    std::string guard = "",
                    ProbabilityType probType = ProbabilityType::CONSTANT,
                    std::string value = "0.789",
                    Label* label=nullptr,
                    Distribution distribution = Distribution::Exponential,
                    std::string distValue="", Policy policy = Policy::PreemptiveRepeatDifferent,
                    Affected affected = Affected::PRS, int x=0, int y=0);
    virtual ~TimedTransition();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    void setDistribution(Distribution d);
    void setDistributionValue(std::string dv);
    void setPolicy(Policy p);
    void setAffected(Affected a);

    Distribution getDistribution();
    std::string getDistributionValue();
    Policy getPolicy();
    Affected getAffected();

    virtual std::string c_str(IData* data=nullptr) const;
//o "rate" daqui é o mesmo q o "valor" do imediato
private:
    Distribution distribution;
    std::string distValue;
    Policy policy;
    Affected affected;

    virtual std::string getClassNodeName();
};
}

#endif // TIMEDTRANSITION_H
