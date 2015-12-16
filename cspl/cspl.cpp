#include "cspl.h"


Cspl::Cspl()
{
}

std::string Cspl::to_ascii_c(spnp::Net *input)
{
    this->net = input;
    std::string content("");

    content = addComment();

    return content;
}

std::string Cspl::addComment()
{
    return "\/*\n*\tCriado pela ferramenta SPNP new GUI.\n"
            "*\tDesenvolvida por Iago Alves da Silva como um substituto\n"
            "*\tdo SPNP-Gui [por K. S. Trivedi - Duke]\n"
            "*\n"
            "*/";
}
