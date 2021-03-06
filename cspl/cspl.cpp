#include "cspl.h"


Cspl::Cspl()
{
}

std::string Cspl::to_ascii_c(spnp::Net *input, std::vector<spnp::OutputFunction> *of)
{
    this->net = input;
    this->of = of;

    addComment();
    ss<<"\n";
    addIncludes();
    ss<<"\n";

    addOptions();
    ss<<"\n";

    addGlobalVars();
    ss<<"\n";

    addNet();
    ss<<"\n";

    addAssert();
    ss<<"\n";
    addAc_Init();
    ss<<"\n";
    addAc_Reach();
    ss<<"\n";

    for(int i=0, size = this->of->size(); i<size; ++i)
    {
        spnp::OutputFunction out = of->at(i);
        out.setFunctionNumber(i);
        ss << out.getFunction();
    }

    addAc_Final();
    ss<<"\n";

    return ss.str();
}

void Cspl::addComment()
{
    this->ss << "/*\n*\tCriado pela ferramenta SPNP new GUI.\n"
             << "*\tDesenvolvida por Iago Alves da Silva como um substituto\n"
             << "*\tdo SPNP-Gui [por K. S. Trivedi - Duke]\n"
             << "*/\n";
}

void Cspl::addIncludes()
{
    std::vector<std::string> *v = new std::vector<std::string>();
    v->push_back("<stdio.h>");
    v->push_back("\"user.h\"");

    //TODO adicionar de acordo com o projeto

    for (int i = 0, total = v->size(); i < total; ++i)
    {
        ss << "#include " << v->at(i) << "\n";
    }
    delete v;
}

void Cspl::addGlobalVars()
{

}

void Cspl::addOptions()
{
    ss << "/*=========Options=========*/\n";
    ss << "void options() {\n";

    //TODO adicionar opções do projeto
    /* hard coded para estado absorvente */
    ss << "iopt(IOP_SSMETHOD, VAL_POWER);\n";
    /* fim hc */

    ss << "}\n";
}

void Cspl::addNet()
{
    ss << "/*=========Definition of the NET=========*/\n";
    ss << "void net() {\n";

    ss << this->net->c_str();
    ss << "}\n";
}

void Cspl::addAssert()
{
    ss << "/*=========Definition of the functions=========*/\n";
    ss << "int assert() {\n";

    //TODO adicionar red

    //ss<< "return -1;\n";

    ss << "}\n";
}

void Cspl::addAc_Init()
{
    ss << "void ac_init() {\n";

    //TODO automatizar
    ss << "/* Information on the net structure */\n";
    ss << "\tpr_net_info();\n";

    ss << "}\n";
}

void Cspl::addAc_Reach()
{
    ss << "void ac_reach() {\n";

    ss << "/* Information on the reachability graph */\n";
    ss << "\tpr_rg_info();\n";

    ss << "}\n";
}

void Cspl::addAc_Final()
{
    ss << "void ac_final() {\n";
    ss << "\tint loop;\n";

    for(int i=0, size=this->of->size(); i<size; ++i)
    {
        spnp::OutputFunction out = this->of->at(i);
        out.setFunctionNumber(i);
        ss << out.getFinal();
    }

    ss << "}\n";
}
