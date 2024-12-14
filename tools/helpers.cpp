module;

#include <iostream>
#include <vector>

export module helpers;

namespace helpers
{

export void print_vector(const std::vector<int>& vec)
{
    for (auto&& element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

} // namespace helpers
