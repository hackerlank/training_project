#include "parameteroptiondata.h"

ParameterOptionData::ParameterOptionData(ParameterOptionData::TYPE type,
                                         ParameterOptionData::AMOUNT amount,
                                         ParameterOptionData::TIME time,
                                         std::string objName,
                                         std::string timeLapse)
{
    this->type = type;
    this->amount = amount;
    this->time = time;
    this->objName = objName;
    this->timeLapse = timeLapse;
}

ParameterOptionData::~ParameterOptionData()
{

}

std::string ParameterOptionData::c_str()
{
    return "";
}
