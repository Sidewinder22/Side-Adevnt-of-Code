#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

import filesystem;
import numbers;

int parserLine(std::string_view str)
{
    std::string numbersInLine;

    for (size_t position = 0; position < str.length(); ++position)
    {
        auto substr = str.substr(position);

        char c = substr.front();
        if (std::isdigit(c))
        {
            numbersInLine.push_back(c);
        }
        else
        {
            for (auto&& digit : numbers::digits)
            {
                if (substr.find(digit.first) == 0)
                {
                    numbersInLine.push_back(digit.second);
                    break;
                }
            }
        }
    }

    std::string number{numbersInLine.front(), numbersInLine.back()};
    return atoi(number.c_str());
}

int main()
{
    auto reader = filesystem::ReadFile("../2023/1/input");
    auto lines  = reader.readLines();

    int sum = 0;
    for (auto&& l : lines)
    {
        auto number = parserLine(l);
        sum += number;
    }

    std::cout << "sum: " << sum << "\n";

    return 1;
}