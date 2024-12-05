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
    ~ReadFile();

    std::vector<std::string> readLines();

private:
    std::ifstream file_;
};

ReadFile::ReadFile(std::string fileName)
    : file_(fileName)
{
    if (!file_.is_open())
    {
        throw std::runtime_error("Can't open file: " + fileName + "!");
    }
}

ReadFile::~ReadFile()
{
    file_.close();
}

std::vector<std::string> ReadFile::readLines()
{
    std::vector<std::string> lines;
    for (std::string line; std::getline(file_, line);)
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
