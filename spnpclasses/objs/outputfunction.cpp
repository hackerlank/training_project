#include "outputfunction.h"

spnp::OutputFunction::OutputFunction(OutputFunction::TYPE type, int functionNum, std::string objId, std::string option)
    :AbstractData()
{
    this->objId = objId;
    this->option = option;
    this->type = type;
    this->functionNumber = functionNum;

    this->vars = "";
    this->functionName = "";
}

spnp::OutputFunction::~OutputFunction()
{

}

XMLNode *spnp::OutputFunction::toXML()
{
    XMLNode* n = AbstractData::toXML();
    n->setAttribute("object_id", this->objId);
    n->setAttribute("option", this->option);
    n->setAttribute("type",static_cast<int>(this->type));

    return n;
}

void spnp::OutputFunction::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->objId = xml->getAttributeS("object_id");
    this->option = xml->getAttributeS("option");
    this->type = static_cast<OutputFunction::TYPE>(xml->getAttributeI("type"));
}

std::string spnp::OutputFunction::c_str(spnp::IData *data) const
{
    (void)data;
    this->prepareData();
}

std::string spnp::OutputFunction::getVariables()
{

}

std::string spnp::OutputFunction::getFunction()
{
    switch (this->type) {
    case TYPE::EXPECTED_TOKEN_PLACE_STEADY:

        break;
    case TYPE::EXPECTED_TOKEN_PLACE_TIME:

        break;
    case TYPE::EXPECTED_TOKEN_PLACES_STEADY:

        break;
    case TYPE::EXPECTED_TOKEN_PLACES_TIME:

        break;

    case TYPE::THROUGHPUT_TRANSITION_STEADY:

        break;
    case TYPE::THROUGHPUT_TRANSITION_TIME:

        break;
    case TYPE::THROUGHPUT_TRANSITIONS_STEADY:

        break;
    case TYPE::THROUGHPUT_TRANSITIONS_TIME:

        break;

    case TYPE::UTILIZATION_TRANSITION_STEADY:

        break;
    case TYPE::UTILIZATION_TRANSITION_TIME:

        break;
    case TYPE::UTILIZATION_TRANSITIONS_STEADY:

        break;
    case TYPE::UTILIZATION_TRANSITIONS_TIME:

        break;

    case TYPE::PROB_PLACE_STEADY:

        break;
    case TYPE::PROB_PLACE_TIME:

        break;
    case TYPE::PROB_PLACES_STEADY:

        break;
    case TYPE::PROB_PLACES_TIME:

        break;

    case TYPE::EXPECTED_REWARD_STEADY:

        break;
    case TYPE::EXPECTED_REWARD_TIME:

        break;
    case TYPE::EXPECTED_ACCUMULATED_ABSORTION:

        break;
    case TYPE::EXPECTED_ACCUMULATED_TIME:

        break;
    case TYPE::STEADY_DEFAULT:

        break;
    case TYPE::VARIABLE:

        break;
    default:
        break;
    }
}


std::string spnp::OutputFunction::getClassNodeName()
{
    return "output_funcion";
}

void spnp::OutputFunction::prepareData()
{
    this->functionName = outFunc + std::to_string(this->functionNumber);

}
