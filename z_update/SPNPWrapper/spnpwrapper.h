#ifndef SPNPWRAPPER_H
#define SPNPWRAPPER_H

#include "spnpwrapper_global.h"

#include <string>

class SPNPW_PUBLIC SPNPWrapper
{

public:
    SPNPWrapper();
    int work(std::string file);

private:
    static bool changedSystemVars;
    const static std::string WORK_TO_DO;

    void exec();
    int changeFolder(std::string to);
    int setEnvVar(std::string var);
    int addSystemVars();
};



#endif // SPNPWRAPPER_H
