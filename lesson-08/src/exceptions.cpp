#include <iostream>

struct A
{
    A(const std::string& name): name(name)
    {
        std::cout << "A(" << name << ")" << std::endl;
    }

    ~A()
    {
        std::cout << "~A(" << name << ")" << std::endl;
    }
    std::string name;
};

struct Error {};
struct FileError : public Error {};

void foo() {
    A a1("a1");
    throw FileError();
}

void bar() {
    A a2("a2");
    try
    {
        A a3("a3");
        foo();
    }
    catch (const Error&)
    {
    }
}

int main()
{
    bar();
}
