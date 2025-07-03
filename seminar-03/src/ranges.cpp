#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int32_t> arr = {1, 2, 3, 4, 5, 6};
    {
        std::vector<int32_t> result;
        result.reserve(arr.size());

        for (auto el : arr)
        {
            if (el % 2 == 0) result.push_back(el * el);
        }
        for (auto el : result) std::cout << el << " ";
        std::cout << "\n";
    }

    {
        auto result = arr |
                      std::views::filter([](int32_t el){ return el % 2 == 0; }) |
                      std::views::transform([](int32_t el) { return el * el; });
        //auto result = std::views::transform([](int32_t el) { return el * el; })(std::views::filter([](int32_t el){ return el % 2 == 0; })(arr));
        for (auto el : result) std::cout << el << " ";
        std::cout << "\n";
    }
}

