#include <iostream>

#include "a.hpp"

void foo()
{
    int i = 1;
    static int static_j = 1;
    static_j += i;
    std::cout << "local i = " << i << std::endl;
    std::cout << "local j = " << static_j << std::endl;
    i += 1;
}

//typedef unsigned long long size_t;

int main()
{
    std::cout << "global var = " << global_var << std::endl;
    std::cout << "static var = " << static_var << std::endl;
    std::cout << "another global var = " << another_global_var << std::endl;
    for (size_t i = 0; i < 10; ++i)
    {
        foo();
    }
    //std::cout << "static local j = " << j << std::endl;
    return 0;
}

