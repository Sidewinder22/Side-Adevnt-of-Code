#include <iostream>
#include <vector>

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
        else
        {
            // remove one element and check once again

            for (size_t i = 0; i < line.size(); ++i)
            {
                std::vector<int> shortenVector;
                for (size_t j = 0; j < line.size(); ++j)
                {
                    if (i != j)
                    {
                        shortenVector.push_back(line[j]);
                    }
                }

                if (numbers::checkOrder(shortenVector, isIncreasing, maxDistance) or
                    numbers::checkOrder(shortenVector, isDecreasing, maxDistance))
                {
                    result++;
                    std::cout << ": +++ safe +++";
                    break;
                }
            }
        }

        std::cout << "\n";
    }

    std::cout << "\nResult: " << result << "\n";
    return 0;
}