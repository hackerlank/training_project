#ifndef PARAMETEROPTIONDATA_H
#define PARAMETEROPTIONDATA_H

#include <string>

class ParameterOptionData
{
public:
    enum TYPE
    {
        PLACE,
        TRANSITION,
        REWARD,
        VARIABLE
    };

    enum AMOUNT
    {
        SINGLE,
        ALL
    };

    enum TIME
    {
        STEADY,
        NOT_STEADY
    };

    ParameterOptionData(TYPE type, AMOUNT amount, TIME time, std::string objName="", std::string timeLapse="");
    ~ParameterOptionData();

    std::string c_str();

private:
    TYPE type;
    AMOUNT amount;
    TIME time;
    std::string objName;
    std::string timeLapse;
};

#endif // PARAMETEROPTIONDATA_H
