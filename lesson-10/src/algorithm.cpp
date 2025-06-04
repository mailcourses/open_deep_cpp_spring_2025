#include <algorithm>
#include <iostream>

int main()
{
    {
        std::string s1{"atbbtdt"};
        std::cout << "before: [" << s1 << "]\n";
        auto it = std::remove(std::begin(s1), std::end(s1), 't');
        std::cout << "after: [" << s1 << "]\n";
        s1.erase(it, std::end(s1));
        std::cout << "final: [" << s1 << "]\n";
    }
    {
        std::string s1{"atbbtdt"};
        std::cout << "before: [" << s1 << "]\n";
        auto it = std::remove_if(std::begin(s1), std::end(s1), [](char ch) { return ch != 't';});
        std::cout << "after: [" << s1 << "]\n";
        s1.erase(it, std::end(s1));
        std::cout << "final: [" << s1 << "]\n";
    }
    /// "hello kitty and" -> "hello%20kitty%20and"
    return 0;
}
