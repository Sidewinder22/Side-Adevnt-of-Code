#include "ReadFile.hpp"
    
ReadFile::ReadFile(std::string fileName)
    : fileName_(fileName)
{ }

std::vector<std::string> ReadFile::read()
{
    std::ifstream file(fileName_);

    if (!file.is_open())
    {
        throw std::runtime_error("Can't open file: " + fileName_);
        // std::cerr << "Can't open file: " << fileName_ << "!\n";
        // return {};
    }

    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line);)
    {
        lines.push_back(line);
    }

    return lines;
}
