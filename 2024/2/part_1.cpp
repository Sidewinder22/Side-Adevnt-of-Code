#include <iostream>

import filesystem;
import numbers;

int main()
{

    auto reader = filesystem::ReadFile("../2024/2/input");
    auto lines  = reader.readAndSplitToInts();

    int result = 0;
    for (auto&& line : lines)
    {
        for (auto&& value : line)
        {
            std::cout << value << " ";
        }

        auto isIncreasing = [](int first, int second) { return first <= second; };
        auto isDecreasing = [](int first, int second) { return first >= second; };
        int  maxDistance  = 3;
        if (numbers::checkOrder(line, isIncreasing, maxDistance) or
            numbers::checkOrder(line, isDecreasing, maxDistance))
        {
            result++;
            std::cout << ": +++ safe +++";
        }

        std::cout << "\n";
    }

    std::cout << "\nResult: " << result << "\n";
    return 0;
}