#include "saveloadfile.h"

#include <fstream>

SaveLoadFile::SaveLoadFile()
{
}

void SaveLoadFile::saveFile(std::string file, std::string text)
{
    std::ofstream output(file);
    output << text;
    output.close();
}

std::string SaveLoadFile::loadFile(std::string file)
{
    std::string line;
    std::string output = "";

    std::ifstream ifs(file);
    while(std::getline(ifs, line))
    {
        output += line;
    }
    return output;
}
