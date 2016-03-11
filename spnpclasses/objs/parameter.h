#ifndef PARAMETER_H
#define PARAMETER_H

#include "abstractdata.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Parameter : public AbstractData
{
    enum FOPTIONS
    {
        ABS_RET_M0,
        PRECISION
    };

    enum IOPTIONS
    {
        PR_MARK_ORDER,
        PR_MERG_MARK,
        PR_FULL_MARK,
        PR_RSET,
        PR_RGRAPH,
        PR_MC,
        PR_MC_ORDER,
        PR_PROB,
        MC,
        OK_ABSMARK,
        OK_VANLOOP,
        OK_TRANS_M0,
        METHOD,
        CUMULATIVE,
        SENSITIVITY,
        ITERATIONS,
        DEBUG,
        USENAME
    };

    enum IVAL
    {
        CANONIC,
        LEXICAL,
        MATRIX,
        YES,
        TANGIBLE,
        FROMTO,
        TOFROM,
        CTMC,
        DTMC,
        NO,
        SSSOR,
        GASEI,
        TSUNIF,
        SSPOWER
    };
public:
    Parameter();
    ~Parameter();
    void setOption(Parameter::IOPTIONS opt, int val);
    void setOption(Parameter::FOPTIONS opt, float val);

    void removeOption(Parameter::IOPTIONS opt);
    void removeOption(Parameter::FOPTIONS opt);

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    virtual std::string c_str(IData* data=nullptr) const;

    virtual std::string getClassNodeName();
private:
    std::map<int, int>* ivalues;
    std::map<int, float>* fvalues;

    std::string getIOptionName(int opt);
    std::string getFOptionName(int opt);

    Parameter::IOPTIONS getIValue(std::string str);
    Parameter::FOPTIONS getFValue(std::string str);

    static const std::string fopt[2];
    static const std::string iopt[18];
};
}
#endif // PARAMETER_H
