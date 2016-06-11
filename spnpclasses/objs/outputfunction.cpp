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

    this->prepareData();
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

    return "";
}

std::string spnp::OutputFunction::getVariables()
{

}

std::string spnp::OutputFunction::getFunciont()
{

}

void spnp::OutputFunction::prepareFunction()
{
    switch (this->type)
    {
    case TYPE::EXPECTED_TOKEN_PLACE_STEADY:
        this->prepareETPS();
        break;
    case TYPE::EXPECTED_TOKEN_PLACE_TIME:
        this->prepareETPT();
        break;
    case TYPE::EXPECTED_TOKEN_PLACES_STEADY:
        this->prepareETPsS();
        break;
    case TYPE::EXPECTED_TOKEN_PLACES_TIME:
        this->prepareETPsT();
        break;

    case TYPE::THROUGHPUT_TRANSITION_STEADY:
        this->prepareTTS();
        break;
    case TYPE::THROUGHPUT_TRANSITION_TIME:
        this->prepareTTT();
        break;
    case TYPE::THROUGHPUT_TRANSITIONS_STEADY:
        this->prepareTTsS();
        break;
    case TYPE::THROUGHPUT_TRANSITIONS_TIME:
        this->prepareTTsT();
        break;

    case TYPE::UTILIZATION_TRANSITION_STEADY:
        this->prepareUTS();
        break;
    case TYPE::UTILIZATION_TRANSITION_TIME:
        this->prepareUTT();
        break;
    case TYPE::UTILIZATION_TRANSITIONS_STEADY:
        this->prepareUTsS();
        break;
    case TYPE::UTILIZATION_TRANSITIONS_TIME:
        this->prepareUTsT();
        break;

    case TYPE::PROB_PLACE_STEADY:
        this->preparePPS();
        break;
    case TYPE::PROB_PLACE_TIME:
        this->preparePPT();
        break;
    case TYPE::PROB_PLACES_STEADY:
        this->preparePPsS();
        break;
    case TYPE::PROB_PLACES_TIME:
        this->preparePPsT();
        break;

    case TYPE::EXPECTED_REWARD_STEADY:
        this->prepareERS();
        break;
    case TYPE::EXPECTED_REWARD_TIME:
        this->prepareERT();
        break;
    case TYPE::EXPECTED_ACCUMULATED_ABSORTION:
        this->prepareEAA();
        break;
    case TYPE::EXPECTED_ACCUMULATED_TIME:
        this->prepareEAT();
        break;
    case TYPE::STEADY_DEFAULT:
        this->prepareSD();
        break;
    case TYPE::VARIABLE:
        this->prepareV();
        break;
    default:
        this->prepareNull();
        break;
    }
}


std::string spnp::OutputFunction::getClassNodeName()
{
    return "output_funcion";
}

void spnp::OutputFunction::prepareData()
{
    this->functionName = "outFunc" + std::to_string(this->functionNumber);
    this->prepareFunction();
}

void spnp::OutputFunction::prepareETPS()
{

}

void spnp::OutputFunction::prepareETPT()
{

}

void spnp::OutputFunction::prepareETPsS()
{

}

void spnp::OutputFunction::prepareETPsT()
{

}

void spnp::OutputFunction::prepareTTS()
{

}

void spnp::OutputFunction::prepareTTT()
{

}

void spnp::OutputFunction::prepareTTsS()
{

}

void spnp::OutputFunction::prepareTTsT()
{

}

void spnp::OutputFunction::prepareUTS()
{

}

void spnp::OutputFunction::prepareUTT()
{

}

void spnp::OutputFunction::prepareUTsS()
{

}

void spnp::OutputFunction::prepareUTsT()
{

}

void spnp::OutputFunction::preparePPS()
{

}

void spnp::OutputFunction::preparePPT()
{

}

void spnp::OutputFunction::preparePPsS()
{

}

void spnp::OutputFunction::preparePPsT()
{

}

void spnp::OutputFunction::prepareERS()
{

}

void spnp::OutputFunction::prepareERT()
{

}

void spnp::OutputFunction::prepareEAA()
{

}

void spnp::OutputFunction::prepareEAT()
{

}

void spnp::OutputFunction::prepareSD()
{

}

void spnp::OutputFunction::prepareV()
{

}

void spnp::OutputFunction::prepareNull()
{

}
