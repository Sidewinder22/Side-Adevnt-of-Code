#include <algorithm>
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

    int result = 0;
    for (auto&& element : firstList)
    {
        int numberOfOccurrences = std::ranges::count(secondList.begin(), secondList.end(), element);
        result += element * numberOfOccurrences;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
