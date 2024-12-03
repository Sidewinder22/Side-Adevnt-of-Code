module;

#include <fstream>
#include <map>
#include <string>
#include <vector>

export module tools;
namespace tools
{

export class ReadFile
{
public:
    ReadFile(std::string fileName);
    std::vector<std::string> read();

private:
    std::string fileName_;
};

ReadFile::ReadFile(std::string fileName)
    : fileName_(fileName)
{
}

std::vector<std::string> ReadFile::read()
{
    std::ifstream file(fileName_);

    if (!file.is_open())
    {
        throw std::runtime_error("Can't open file: " + fileName_);
    }

    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line);)
    {
        lines.push_back(line);
    }

    return lines;
}

export std::map<std::string, char> digits = {
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'},
};

} // namespace tools
