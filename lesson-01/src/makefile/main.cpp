#include "vector.hpp"

int main()
{
    Vector arr;
    for (std::size_t i = 0; i < 15; ++i)
    {
        arr.push_back(i);
        arr.pop_back();
    }

    return 0;
}
