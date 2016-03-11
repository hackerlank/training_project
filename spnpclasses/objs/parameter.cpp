#include "parameter.h"

spnp::Parameter::Parameter()
{

}

spnp::Parameter::~Parameter()
{

}

void spnp::Parameter::setOption(spnp::Parameter::IOPTIONS opt, int val)
{

}

void spnp::Parameter::setOption(spnp::Parameter::FOPTIONS opt, float val)
{

}

void spnp::Parameter::removeOption(spnp::Parameter::IOPTIONS opt)
{

}

void spnp::Parameter::removeOption(spnp::Parameter::FOPTIONS opt)
{

}

XMLNode *spnp::Parameter::toXML()
{

}

void spnp::Parameter::fromXML(XMLNode *xml)
{

}

std::string spnp::Parameter::c_str(spnp::IData *data) const
{

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

