module;

#include <fstream>
#include <vector>

export module filesystem;
namespace filesystem
{

namespace
{
constexpr int begin = 0;
}

export class ReadFile
{
public:
    ReadFile(std::string fileName);
    ~ReadFile();

    std::vector<std::string>      readLines();
    std::vector<std::vector<int>> readAndSplitToInts();

private:
    std::vector<int> split(std::string& line, const std::string& separator);
    std::ifstream    file_;
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

std::vector<std::vector<int>> ReadFile::readAndSplitToInts()
{
    auto lines = readLines();

    std::vector<std::vector<int>> result;
    for (auto&& line : lines)
    {
        result.push_back(split(line, " "));
    }

    return result;
}

std::vector<int> ReadFile::split(std::string& line, const std::string& separator)
{
    std::vector<int>       result;
    std::string::size_type position = 0;
    while ((position = line.find(separator)) != std::string::npos)
    {
        auto str = line.substr(begin, position);
        if (!str.empty())
        {
            result.push_back(std::stoi(str));
        }
        line = line.substr(position + 1);
    }

    result.push_back(std::stoi(line));
    return result;
}

} // namespace filesystem
