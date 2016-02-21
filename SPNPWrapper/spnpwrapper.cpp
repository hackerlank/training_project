#include "spnpwrapper.h"

//chdir
#include <unistd.h>
//cout
#include <iostream>
//file
#include <fstream>

SPNPWrapper::SPNPWrapper()
{
}

void SPNPWrapper::exec()
{
    FILE *in;
    char buff[512];
    if((in = popen(WORK_TO_DO.c_str(), "r")))
    {
        while(fgets(buff, sizeof(buff), in)!=NULL)
        {
            std::cout << buff;
        }
    }

    pclose(in);
}

int SPNPWrapper::changeFolder(std::string to)
{
    int ret = chdir(to.c_str());
    return ret;
}

int SPNPWrapper::setEnvVar(std::string var)
{
    char * c = const_cast<char*>(var.c_str());
    int p = putenv(c);
    if(p!=0)
    {
        std::cout << "PAU!" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int SPNPWrapper::addSystemVars()
{
    //bool out = false;
    if(!changedSystemVars)
    {
#ifdef LINUX
        std::fstream file("lvars.ini");


         * PLATFORM=linux
         * DIR=/home/iago/estudo
         * //SPN=/home/iago/estudo/spnp/Examples/si
         */
#elif WINDOWS
        std::fstream file("wvars.ini");

        /* wvars.txt
         * SPNP_DIRECTORY=F:/spnp
         * PATH=F:/spnp/bin
         * //SPN=F:/spnp/molloy
         */
#endif
        std::string str;
        while(std::getline(file, str))
        {
            if(setEnvVar(str) == EXIT_FAILURE)
                return EXIT_FAILURE;
        }
        changedSystemVars = true;
    }
    return EXIT_SUCCESS;
}

int SPNPWrapper::work(std::string file)
{
    //get file folder
    std::string prefix = file.substr(0, file.find_last_of('/'));

    if(addSystemVars() != EXIT_FAILURE)
    {
        //goes to file folder
        if(changeFolder(prefix) != 0)
        {
            std::cout << "error changing folder" << std::endl;
            return EXIT_FAILURE;
        }
        setEnvVar("SPN="+file);
        exec();
    }
    else
        std::cout << "error adding system vars" << std::endl;
    return EXIT_SUCCESS;
}

#ifdef LINUX
        const std::string SPNPWrapper::WORK_TO_DO = "make -f %SPNP_DIRECTORY%/Makerun_gcc";
#elif WINDOWS
        const std::string SPNPWrapper::WORK_TO_DO = "make -f %SPNP_DIRECTORY%/Makerun.dos";
#endif

bool SPNPWrapper::changedSystemVars = false;
