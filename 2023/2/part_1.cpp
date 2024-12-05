#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

import tools;

const std::string colonDelimiter            = ":";
const std::string semicolonDelimiter        = ";";
const std::string numberRegexPhrase         = "[0-9]+";
const std::string numberAndSpaceRegexPhrase = numberRegexPhrase + "\\s";
const std::regex  numberRegex(numberRegexPhrase);
const std::regex  numberAndSpaceRegex(numberAndSpaceRegexPhrase);

std::map<std::string, int> maxLoads = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
};

std::string applyRegex(const std::string& str, std::regex r)
{
    std::smatch match;
    std::regex_search(str, match, r);

    return match[0].str();
}

int extractGameIdAndRemoveItFromLine(std::string& str)
{
    auto pos   = str.find_first_of(colonDelimiter);
    auto token = str.substr(0, pos);
    str.erase(0, pos + colonDelimiter.length());

    auto result = applyRegex(token, numberRegex);
    return atoi(result.c_str());
}

std::vector<std::string> extractGameSets(std::string& line)
{
    size_t                   pos = 0;
    std::vector<std::string> gameSets;

    while ((pos = line.find_first_of(semicolonDelimiter)) != std::string::npos)
    {
        gameSets.push_back(line.substr(0, pos));
        line.erase(0, pos + semicolonDelimiter.length());
    }
    // add the last one set
    gameSets.push_back(line.substr(0, pos));

    return gameSets;
}

int extractNumber(const std::string& gameSet, const std::string& color)
{
    std::regex colorRegex(numberAndSpaceRegexPhrase + color);

    auto findings = applyRegex(gameSet, colorRegex);
    if (findings.empty())
    {
        return 0;
    }

    auto result = applyRegex(findings, numberRegex);
    return atoi(result.c_str());
}

int parseLine(std::string& line)
{
    auto gameId = extractGameIdAndRemoveItFromLine(line);
    auto sets   = extractGameSets(line);
    for (auto&& set : sets)
    {
        for (auto&& load : maxLoads)
        {
            if (extractNumber(set, load.first) > load.second)
            {
                return false;
            }
        }
    }

    return gameId;
}

int main()
{
    int  sum    = 0;
    auto reader = tools::ReadFile("../2023/2/input");
    auto lines  = reader.readLines();

    for (auto&& l : lines)
    {
        sum += parseLine(l);
    }
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}