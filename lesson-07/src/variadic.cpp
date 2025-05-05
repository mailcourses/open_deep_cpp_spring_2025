#include <iostream>

template <class T>
void print(T&& val)
{
    std::cout << val << '\n';
}

template <class T, class... Args>
void print(T&& val, Args&&... args)
{
    std::cout << val << '\n';
    print(std::forward<Args>(args)...);
}

template<class... Args>
void printFold(Args&&... args)
{
    (std::cout << ... << args) << '\n';
}

int main()
{
    print("Hello", 100500, 5.0, 1, 2, 3, 4, 5, 6);
    printFold("Hello", 100500, 5.0, 1, 2, 3, 4, 5, 6);
}
