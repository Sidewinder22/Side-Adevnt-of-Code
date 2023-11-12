#include <iostream>
#include <string>
#include <vector>
// #include "tools/include/ReadFile.hpp"
#include "ReadFile.hpp"

int main()
{
    std::string fileName = "../2022/7/example_input";

    ReadFile file(fileName);
    std::vector<std::string> lines;
    try 
    {
        lines = file.read();
    }
    catch (const std::runtime_error &error)
    {
        std::cerr << "RuntimeError: " << error.what() << std::endl;
        return 1;
    }

    for (auto && l : lines)
    {
        std::cout << l << "\n";
    }


    return 0;
}