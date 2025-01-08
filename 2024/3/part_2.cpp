#include <iostream>
#include <regex>

import filesystem;
import numbers;

int main()
{
    auto reader = filesystem::ReadFile("../2024/3/input");
    auto lines  = reader.readLines();

    std::regex mulRegex(R"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))");

    int  result   = 0;
    bool multiply = true;
    for (auto&& line : lines)
    {
        for (std::smatch match; std::regex_search(line, match, mulRegex);)
        {
            std::string phrase = match.str();
            if (phrase == "do()")
            {
                multiply = true;
            }
            else if (phrase == "don't()")
            {
                multiply = false;
            }
            else
            {
                if (multiply)
                {
                    auto numbers = numbers::extractNumbers(phrase);
                    result += numbers[0] * numbers[1];
                }
            }

            line = match.suffix();
        }
    }

    std::cout << "\nResult: " << result << "\n";
    return 0;
}
