#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    std::vector<int> firstList;
    std::vector<int> secondList;

    std::ifstream file("../2024/1/input");
    if (!file.is_open())
    {
        throw std::runtime_error("Can't open file!");
    }

    int number1, number2 = 0;
    while (file >> number1 >> number2)
    {
        firstList.push_back(number1);
        secondList.push_back(number2);
    }

    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    int result = 0;
    for (size_t i = 0; i < firstList.size(); i++)
    {
        result += abs(firstList[i] - secondList[i]);
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
