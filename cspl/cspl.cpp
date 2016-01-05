#include "cspl.h"


Cspl::Cspl()
{
}

std::string Cspl::to_ascii_c(spnp::Net *input)
{
    this->net = input;

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

    ss << "}\n";
}

void Cspl::addNet()
{
    ss << "/*=========Definition of the NET=========*/\n";
    ss << "void net() {\n";

    //TODO adicionar rede
    //lugares (não apagar o ponteiro!!!)
    std::vector<spnp::Place*>* places = this->net->getPlaces();
    if(places->size()>0)
    {
        ss << "/* Place */\n";
        for (int i = 0, total = places->size(); i < total; ++i)
        {
            spnp::Place* place = places->at(i);
            ss << "place(\"" << place->getName() << "\");\n";
            if(place->getToken().compare("0")!=0)
            {
                ss<< "init(\"" << place->getName() << "\"," << place->getToken() << ");\n";
            }
        }
    }

    std::vector<spnp::ImmediateTransition*>* trans = this->net->getTransitions();
    if(trans->size()>0)
    {
        ss << "/* Transition */\n";
        for (int i = 0, total = trans->size(); i < total; ++i)
        {
            spnp::ImmediateTransition* it = trans->at(i);
            ss << "imm(\"" << it->getName() << "\");\n";
            if(it->getGuard().compare("") != 0)
            {
                ss << "guard(\"" << it->getName() << "\", " << it->getGuard() << ");\n";
            }
            ss << "priority(\""<< it->getName() << "\"," << it->getPriority() << ");\n";

            if(it->getGuard().compare("") != 0) //outras funções
            {
                switch (it->getProbType())
                {
                case spnp::ImmediateTransition::CONSTANT:
                    ss << "probval(\"" << it->getName() << "\", " << it->getValue() << ");\n";
                    break;
                case spnp::ImmediateTransition::PLACE_DEPENDENT:

                    break;
                case spnp::ImmediateTransition::FUNCTION:

                    break;
                default:
                    break;
                }
            }

        }
    }


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

    //TODO adicionar init

    ss << "}\n";
}

void Cspl::addAc_Reach()
{
    ss << "void ac_reach() {\n";

    //TODO adicionar reach

    ss << "}\n";
}

void Cspl::addAc_Final()
{
    ss << "void ac_final() {\n";

    //TODO adicionar final

    ss << "}\n";
}
