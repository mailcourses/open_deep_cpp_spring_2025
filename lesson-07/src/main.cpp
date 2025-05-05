#include "vector.hpp"
#include <map>
#include <vector>

struct Foo
{
    Foo() = default;

    Foo operator+(const Foo& rhs)
    {
        return Foo();
    }
};

template<class T, double Y = 5.0>
double foo(T a)
{
    return a + Y;
}

int main()
{
    {
        const size_t capacity = 10;
        my::vector<int> v1(capacity);
        my::vector<int> v2(capacity);
        my::vector<int> v3 = v1 + v2;

        my::vector<Foo> v4(capacity);
        my::vector<Foo> v5 = v4 + v4;

        foo(10);
    }

    {
        std::map<std::string, std::vector<int64_t>> m;
        //for (auto elem : m)
        m["a"] = std::vector<int64_t>{1,2};
        //std::map<std::string, std::vector<int64_t>>::iterator it = m.begin();
        auto it = m.begin();
        std::map<std::string, std::vector<int64_t>>::const_iterator it_end = m.end();
        for (; it != it_end; ++it)
        {
            std::cout << it->first << std::endl;
            //m.insert(std::make_pair(it->first + it->first, std::vector<int64_t>()));
        }
    }
}
