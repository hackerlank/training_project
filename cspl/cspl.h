#ifndef CSPL_H
#define CSPL_H

#include "cspl_global.h"
#include "objs/net.h"

class CSPL_PUBLIC Cspl
{

public:
    Cspl();
    std::string to_ascii_c(spnp::Net *input);

    std::string addComment();

private:
    spnp::Net* net;
};

#endif // CSPL_H
