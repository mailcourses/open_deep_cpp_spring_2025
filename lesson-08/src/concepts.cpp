#include <iostream>

struct A
{
    void foo(int32_t) const {}
};

struct B
{
    void boo(int32_t) const {}
};

struct C
{
    void foo() const {}
};

template<typename T>
concept HasFoo =
    requires (T t) {
        { t.foo(100) } -> std::same_as<void>;
    };

template<HasFoo T>
void optimize(const T& obj)
{
    obj.foo(100500);
    std::cout << "object calls with foo: " << typeid(obj).name() << std::endl;
}

template<typename T>
void optimize(const T& obj)
{
    // какая-нибудь сложная логика с obj.
    std::cout << "object without foo function: " << typeid(obj).name() << std::endl;
}

int main()
{
    std::cout << std::boolalpha << std::is_pod<int>::value << std::endl;
    {
        A a;
        optimize(a);
    }
    {
        B b;
        optimize(b);
    }
    {
        C c;
        optimize(c);
    }
}
