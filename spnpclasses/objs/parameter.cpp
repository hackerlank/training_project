#include "parameter.h"

spnp::Parameter::Parameter()
{
    this->ivalues = new std::map<int, int>();
    this->fvalues = new std::map<int, float>();
}

spnp::Parameter::~Parameter()
{
    delete this->ivalues;
    delete this->fvalues;
}

void spnp::Parameter::setOption(spnp::Parameter::IOPTIONS opt, int val)
{
    this->ivalues->insert(std::pair<int, int>((int)opt, val));
}

void spnp::Parameter::setOption(spnp::Parameter::FOPTIONS opt, float val)
{
    this->fvalues->insert(std::pair<int, float>((int)opt, val));
}

void spnp::Parameter::removeOption(spnp::Parameter::IOPTIONS opt)
{
    this->ivalues->erase((int)opt);
}

void spnp::Parameter::removeOption(spnp::Parameter::FOPTIONS opt)
{
    this->fvalues->erase((int)opt);
}

XMLNode *spnp::Parameter::toXML()
{
    XMLNode *node = AbstractData::toXML();

    for(std::map<int,int>::iterator iter = ivalues->begin(); iter != ivalues->end(); ++iter)
    {
        XMLNode *t = new XMLNode("ivalue");
        std::string first = getIOptionName(iter->first);
        std::string second = std::to_string(iter->second);
        t->setAttribute("iopt", first);
        t->setAttribute("value", second);
        node->addChild(t);
        /*
         * <ivalue iopt="PR_MARK_FULANO" value="123">
         *
         * */
    }

    for(std::map<int,float>::iterator iter = fvalues->begin(); iter != fvalues->end(); ++iter)
    {
        XMLNode *t = new XMLNode("fvalue");
        std::string first = getIOptionName(iter->first);
        t->setAttribute("fopt", first);
        t->setAttribute("value", iter->second);
        node->addChild(t);
    }
}

void spnp::Parameter::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    delete this->ivalues;
    delete this->fvalues;

    this->ivalues = new std::map<int, int>();
    this->fvalues = new std::map<int, float>();

    std::vector<XMLNode*> *v = xml->getChildrenByName("ivalue");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        XMLNode *node = *it;
        Parameter::IOPTIONS key = getIValue(node->getAttributeS("iopt"));
        int value = node->getAttributeI("value");

        this->setOption(key, value);
    }
    delete v;

    v = xml->getChildrenByName("fvalue");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        XMLNode *node = *it;
        Parameter::FOPTIONS key = getFValue(node->getAttributeS("fopt"));
        int value = node->getAttributeI("value");

        this->setOption(key, value);
    }
    delete v;
}

std::string spnp::Parameter::c_str(spnp::IData *data) const
{
    //TODO fazer engenharia reversa
}

std::string spnp::Parameter::getClassNodeName()
{
    return "parameter";
}

std::string spnp::Parameter::getIOptionName(int opt)
{
    return this->iopt[opt];
}

std::string spnp::Parameter::getFOptionName(int opt)
{
    return this->iopt[opt];
}

spnp::Parameter::IOPTIONS spnp::Parameter::getIValue(std::string str)
{
    int i;
    for(int size = (sizeof(iopt)/sizeof(*iopt)); i<size; ++i)
    {
        if(iopt[i].compare(str)==0)
        {
            break;
        }
    }
    return static_cast<Parameter::IOPTIONS>(i);
}

spnp::Parameter::FOPTIONS spnp::Parameter::getFValue(std::string str)
{
    int i;
    for(int size = (sizeof(fopt)/sizeof(*fopt)); i<size; ++i)
    {
        if(fopt[i].compare(str)==0)
        {
            break;
        }
    }
    return static_cast<Parameter::FOPTIONS>(i);
}


const std::string spnp::Parameter::fopt[2] = { "FOP_ABS_RET_M0", "FOP_PRECISION" };
const std::string spnp::Parameter::iopt[18] = { "IOP_PR_MARK_ORDER", "IOP_PR_MERG_MARK",
                                                "IOP_PR_FULL_MARK", "IOP_PR_RSET",
                                                "IOP_PR_RGRAPH", "IOP_PR_MC",
                                                "IOP_PR_MC_ORDER", "IOP_PR_PROB",
                                                "IOP_MC", "IOP_OK_ABSMARK",
                                                "IOP_OK_VANLOOP", "IOP_OK_TRANS_M0",
                                                "IOP_METHOD", "IOP_CUMULATIVE",
                                                "IOP_SENSITIVITY","IOP_ITERATIONS",
                                                "IOP_DEBUG", "IOP_USENAME" };

