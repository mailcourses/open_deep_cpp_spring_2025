#include <iostream>

struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
        data_ = new int[1024];
    }

    //~A() noexcept(false) <-- так делать не надо!!!
    ~A()
    {
        std::cout << "~A()" << std::endl;
        delete[] data_;
        try {
            throw 1;
        }
        catch (...)
        {
        }
    }

    int* data_ = nullptr;
};

int main()
{
    try {
        A a;
    }
    catch(...)
    {
        std::cout << "catched" << std::endl;
    }
}
