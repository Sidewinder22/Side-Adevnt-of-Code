#include <array>
#include <iostream>
#include <regex>

import filesystem;
import numbers;

int main()
{
    auto reader = filesystem::ReadFile("../2024/3/input");
    auto lines  = reader.readLines();

    std::regex mulRegex(R"(mul\(\d{1,3},\d{1,3}\))");

    int result = 0;
    for (auto&& line : lines)
    {
        for (std::smatch mulSMatch; std::regex_search(line, mulSMatch, mulRegex);)
        {
            std::string mulPhrase = mulSMatch.str();
            auto        numbers   = numbers::extractNumbers(mulPhrase);

            result += numbers[0] * numbers[1];
            line = mulSMatch.suffix();
        }
    }

    std::cout << "\nResult: " << result << "\n";
    return 0;
}
