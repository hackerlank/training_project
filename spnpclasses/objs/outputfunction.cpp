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
    this->functionString = "";
    this->finalString = "";

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
    return this->vars;
}

std::string spnp::OutputFunction::getFunction()
{
    return this->functionString;
}

std::string spnp::OutputFunction::getFinal()
{
    return this->finalString;
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
    this->functionString = "double " + this->functionName + "() {\n";
    this->functionString+= "\treturn(mark("+ objId +"));\n}\n";

    this->finalString = "\tsolve(INFINITY);\n";
    this->finalString += "pr_expected(\"Expected # of tokens of the place "+ objId + " in steady-state\","+ this->functionName +")";
}

void spnp::OutputFunction::prepareETPT()
{
    this->functionString = "double " + this->functionName + "() {\n";
    this->functionString+= "\treturn(mark("+ objId +"));\n}\n";

    std::vector<std::string> data = this->split(this->option);
    this->finalString = "for(loop=" + data.at(0)+";loop<"+data.at(1)+";loop+="+data.at(2)+") {\n";
    this->finalString += "\tsolve((double) loop);\n";
    this->finalString += "\tpr_expected(\"Expected # of tokens of the place "+objId+"\","+this->functionName+");";
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

std::vector<std::string> spnp::OutputFunction::split(std::string in)
{
    std::vector<std::string> out;
    int index = -1;
    do
    {
        index = in.find(',');
        if(index>-1)
        {
            out.push_back(in.substr(0, index));
            in = in.substr(index, in.size());
        }
    } while(index > -1);

    return out;
}
