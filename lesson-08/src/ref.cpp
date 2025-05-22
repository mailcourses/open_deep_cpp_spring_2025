#include <iostream>

struct A
{
};

template<typename T>
void boo(const T& t)
{
    std::cout << "lvalue boo" << std::endl;
}

template<typename T>
void boo(const T&& t)
{
    std::cout << "rvalue boo" << std::endl;
}

template<typename T>
void foo(T&& t)
{
    boo(std::forward<T>(t));
}

int main()
{
    A a;
    foo(a);
    foo(std::move(a));
    boo(a);
    boo(std::move(a));
}
