#ifndef OUTPUTFUNCTION_H
#define OUTPUTFUNCTION_H

//#include "abstractdata.h"
#include "objs/net.h"

namespace spnp
{
/**
 * @brief O tipo de saída de dado a ser analisado.
 */
class SPNPCLASSES_PUBLIC OutputFunction : public AbstractData
{
public:
    enum TYPE
    {
        EXPECTED_TOKEN_PLACE_STEADY,
        EXPECTED_TOKEN_PLACE_TIME,
        EXPECTED_TOKEN_PLACES_STEADY,
        EXPECTED_TOKEN_PLACES_TIME,

        THROUGHPUT_TRANSITION_STEADY,
        THROUGHPUT_TRANSITION_TIME,
        THROUGHPUT_TRANSITIONS_STEADY,
        THROUGHPUT_TRANSITIONS_TIME,

        UTILIZATION_TRANSITION_STEADY,
        UTILIZATION_TRANSITION_TIME,
        UTILIZATION_TRANSITIONS_STEADY,
        UTILIZATION_TRANSITIONS_TIME,

        PROB_PLACE_STEADY,
        PROB_PLACE_TIME,
        PROB_PLACES_STEADY,
        PROB_PLACES_TIME,

        EXPECTED_REWARD_STEADY,
        EXPECTED_REWARD_TIME,
        EXPECTED_ACCUMULATED_ABSORTION,
        EXPECTED_ACCUMULATED_TIME,
        STEADY_DEFAULT,
        VARIABLE
    };

    OutputFunction(OutputFunction::TYPE type, std::string objId="", std::string option="", spnp::Net *net=nullptr);
    ~OutputFunction();

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);
    void setFunctionNumber(int num);
    virtual std::string c_str(IData* data=nullptr) const;

    std::string getVariables();
    std::string getFunction();

    std::string getFinal();

    std::string getDescription();
protected:
    virtual std::string getClassNodeName();

    std::string objId;
    std::string option;
    OutputFunction::TYPE type;

private:
    void prepareData();
    void prepareFunction();

    std::string vars;
    int functionNumber;
    std::string functionName;
    std::string functionString;

    std::string descriptionString;
    std::string finalString;

    spnp::Net *net;

    void prepareETPS();
    void prepareETPT();
    void prepareETPsS();
    void prepareETPsT();

    void prepareTTS();
    void prepareTTT();
    void prepareTTsS();
    void prepareTTsT();

    void prepareUTS();
    void prepareUTT();
    void prepareUTsS();
    void prepareUTsT();

    void preparePPS();
    void preparePPT();
    void preparePPsS();
    void preparePPsT();

    void prepareERS();
    void prepareERT();
    void prepareEAA();
    void prepareEAT();
    void prepareSD();
    void prepareV();

    void prepareNull();

    std::vector<std::string> split(std::string in);
};
}
#endif // OUTPUTFUNCTION_H
