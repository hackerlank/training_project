#ifndef SPNPWRAPPER_H
#define SPNPWRAPPER_H

#include "spnpwrapper_global.h"

#include <string>

class SPNPWRAPPER_PUBLIC SPNPWrapper
{

public:
    SPNPWrapper(std::string dir
        #ifdef WINDOWS
            , std::string path
        #endif
            );
    int work(std::string file);

private:
    static bool changedSystemVars;
    const static std::string WORK_TO_DO;

    void exec();
    int changeFolder(std::string to);
    int setEnvVar(std::string var);
    int addSystemVars();

    std::string dir;
#ifdef WINDOWS
    std::string path;
#endif
};

#endif // SPNPWRAPPER_H
