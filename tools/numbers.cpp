module;

#include <functional>
#include <map>
#include <string>
#include <vector>

export module numbers;

namespace numbers
{

export std::map<std::string, char> digits = {
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'},
};

export bool checkOrder(const std::vector<int>& numbers, std::function<bool(int, int)> condition,
                       int maxDistance)
{
    bool result = true;
    for (size_t i = 0; i < numbers.size() - 1; ++i)
    {
        if (condition(numbers[i], numbers[i + 1]))
        {
            result = false;
            break;
        }
        else if (std::abs(numbers[i] - numbers[i + 1]) > maxDistance)
        {
            result = false;
            break;
        }
    }

    return result;
}

} // namespace numbers
