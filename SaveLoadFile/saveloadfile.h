#ifndef SAVELOADFILE_H
#define SAVELOADFILE_H

#include "saveloadfile_global.h"

#include <string>

class SL_PUBLIC SaveLoadFile
{

public:
    SaveLoadFile();

    void saveFile(std::string file, std::string text);
    std::string loadFile(std::string file);

    /*
    //http://www.codeproject.com/Articles/540912/Cplusplus-Threads-Make-your-multitasking-life-e
    std::thread t1(saveFile, "file.xml", "algo de saída");
    t1.join();

    std::future<std::string> f1 = std::async(std::launch::async, loadFile, "file.xml");
    std::cout << f1.get() << std::endl;
    */
};

#endif // SAVELOADFILE_H
