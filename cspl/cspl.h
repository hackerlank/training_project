#ifndef CSPL_H
#define CSPL_H

#include "cspl_global.h"
#include "objs/net.h"
#include <sstream>

class CSPL_PUBLIC Cspl
{

public:
    Cspl();
    std::string to_ascii_c(spnp::Net *input);

    void addComment();
    void addIncludes();
    void addGlobalVars();
    void addOptions();
    void addNet();
    void addAssert();
    void addAc_Init();
    void addAc_Reach();
    void addAc_Final();


private:
    spnp::Net* net;
    std::stringstream ss;
};

#endif // CSPL_H
