#include <iostream>
#include <fstream>

#include <thread>
#include <future>

using namespace std;

void createFile(std::string file, std::string text)
{
    std::ofstream output(file);
    output << text;
    output.close();
}

std::string readFile(std::string file)
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

int main()
{
    //http://www.codeproject.com/Articles/540912/Cplusplus-Threads-Make-your-multitasking-life-e
    std::thread t1(createFile, "file.xml", "algo de saída");
    t1.join();

    std::future<std::string> f1 = std::async(std::launch::async, readFile, "file.xml");
    std::cout << f1.get() << std::endl;

    return 0;
}

