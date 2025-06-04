#include <iostream>
#include <vector>

struct Foo
{
    uint32_t age;
    std::string name;
    Foo() = default;
    Foo(uint32_t age, const std::string& name): age(age), name(name) {}
};

int main()
{
    {
        std::vector<int32_t> v1;
        std::cout << v1.size() << ":" << v1.capacity() << std::endl;
        v1.push_back(100);
        std::cout << "After pushing 100: " << v1.size() << ":" << v1.capacity() << std::endl;
        v1.resize(100);
        v1.emplace_back(52);
        v1.resize(10);
        v1.shrink_to_fit();
        std::cout << "After emplacing back: " << v1.size() << ":" << v1.capacity() << std::endl;
    }
    {
        std::vector<Foo> v1(10);
        std::cout << v1.size() << ":" << v1.capacity() << std::endl;
        v1.push_back(Foo(52, "Say my name"));
        std::cout << "After pushing 100: " << v1.size() << ":" << v1.capacity() << std::endl;
        v1.emplace_back(52, "Say my name");
        std::cout << "After emplacing back: " << v1.size() << ":" << v1.capacity() << std::endl;
    }
    {
        std::vector<int32_t> v1;
        v1.reserve(10);
        std::cout << v1.size() << ":" << v1.capacity() << std::endl;
        v1.push_back(100);
        std::cout << "After pushing 100: " << v1.size() << ":" << v1.capacity() << std::endl;
        v1.emplace_back(52);
        std::cout << "After emplacing back: " << v1.size() << ":" << v1.capacity() << std::endl;
    }

    {
        std::vector<char> m1(10, 'o');
        //std::vector<std::vector<char>> m2(10, {'o', 'o', 'o'});
        std::vector<std::vector<char>> m2(10, std::vector<char>(100, 'o'));// m2[0] = std::vector<char>(100, 'o');
                                                                           // m2[1] = std::vector<char>(100, 'o');...
        std::cout << m2.size() << "x" << m2.back().size() << std::endl;
    }

    {
        std::vector<int64_t> v1(1024);
        std::cout << v1.size() << ":" << v1.capacity() << std::endl;
        //...
        v1.clear();
        std::cout << "After clearing: " << v1.size() << ":" << v1.capacity() << std::endl;
        //v1.shrink_to_fit();
        std::vector<int64_t>().swap(v1);
        std::cout << "After shrinking: " << v1.size() << ":" << v1.capacity() << std::endl;
    }
}
