#include <iostream>
#include <type_traits>
#include <limits>

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

namespace my
{

template<typename T>
struct has_foo
{
    static int check(...);

    template<typename U>
    static auto check(U* u) -> decltype(u->foo(100500));

    static constexpr bool value = std::is_same<void, decltype(has_foo<T>::check((T*)nullptr))>::value;
};

} // namespace my

template<typename T>
void optimize(const T& obj,
              typename std::enable_if<my::has_foo<T>::value>::type* = nullptr)
{
    obj.foo(100500);
    std::cout << "object calls with foo: " << typeid(obj).name() << std::endl;
}

template<typename T>
void optimize(const T& obj,
              typename std::enable_if<!my::has_foo<T>::value>::type* = nullptr)
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

    std::cout << "max int64_t: " << std::numeric_limits<int64_t>::max() << std::endl;
    std::cout << "max uint32_t: " << std::numeric_limits<uint32_t>::max() << std::endl;
}
