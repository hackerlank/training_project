#ifndef CSPL_H
#define CSPL_H

#include "cspl_global.h"
#include "objs/net.h"
#include "objs/outputfunction.h"
#include <sstream>

class CSPL_PUBLIC Cspl
{

public:
    Cspl();
    std::string to_ascii_c(spnp::Net *input, std::vector<spnp::OutputFunction> *of);

private:
    spnp::Net* net;
    std::vector<spnp::OutputFunction> *of;
    std::stringstream ss;

    void addComment();
    void addIncludes();
    void addGlobalVars();
    void addOptions();
    void addNet();
    void addAssert();
    void addAc_Init();
    void addAc_Reach();
    void addAc_Final();
};

#endif // CSPL_H
