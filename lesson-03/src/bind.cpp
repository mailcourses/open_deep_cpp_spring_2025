#include <iostream>
#include <functional>

void foo(int a, double b, const std::string &c)
{
    std::cout << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
}

bool lessThan(int v, int max)
{
    return v < max;
}

int main()
{
    foo(1, 2.5f, "hello");
    std::string str{"hello, Peter"};
    auto boo = std::bind(foo, std::placeholders::_1, std::placeholders::_2, std::ref(str));
    boo(2, 3.5f);
    auto moo = [](int a, double b) { return foo(a, b, "Hello, Jessy"); };
    moo(3, 4.5f);

    auto lessThan3 = std::bind(lessThan, std::placeholders::_1, 3);
    std::vector<int> v(1000, -1);
    if (std::all_of(v.begin(), v.end(), lessThan3))
    {
    }

    for (size_t i = 0; i < v.size(); ++i)
    {
        if (lessThan3(v[i])) break;
    }

    return 0;
}

