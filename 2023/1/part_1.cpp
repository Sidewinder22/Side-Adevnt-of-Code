#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

import filesystem;

int parserLine(std::string_view str)
{
    std::string numberInLine;
    for (auto&& c : str)
    {
        if (std::isdigit(c))
        {
            numberInLine.push_back(c);
        }
    }

    std::string number{numberInLine.front(), numberInLine.back()};
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

    return 0;
}
