#include <array>
#include <iostream>
#include <regex>

import filesystem;

int main()
{
    auto reader = filesystem::ReadFile("../2024/3/input");
    // auto reader = filesystem::ReadFile("../2024/3/test_input");
    auto lines = reader.readLines();

    std::regex mulRegex(R"(mul\(\d{1,3},\d{1,3}\))");
    std::regex numRegex(R"(\d{1,3})");

    int result = 0;
    for (auto&& line : lines)
    {
        for (std::smatch mulSMatch; std::regex_search(line, mulSMatch, mulRegex);)
        {
            std::string      mulPhrase = mulSMatch.str();
            std::vector<int> numbers;

            for (std::smatch numSMatch; std::regex_search(mulPhrase, numSMatch, numRegex);)
            {
                numbers.push_back(std::stoi(numSMatch.str()));
                mulPhrase = numSMatch.suffix();
            }

            line = mulSMatch.suffix();
            result += numbers[0] * numbers[1];
        }
    }

    std::cout << "\nResult: " << result << "\n";
    return 0;
}
