#include <iostream>
#include <map>

template<typename C, typename I>
auto authAndAccess(C &container, I index) -> decltype(container[index])
{
    //authenticateUser();
    return container[index];
}

int main()
{
    std::map<std::string, int64_t> v;
    authAndAccess(v, "abc");
}
