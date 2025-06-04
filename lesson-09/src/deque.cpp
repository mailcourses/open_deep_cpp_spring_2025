#include <iostream>
#include <deque>

int main()
{
    {
        std::deque<std::string> d1 = {"1", "2", "3"};
        const size_t n = d1.size();
        std::cout << d1.size() << std::endl;

        std::cout << d1[n-1] << std::endl;
        std::cout << d1[n] << std::endl;
        try
        {
            std::cout << d1.at(n) << std::endl;
        } catch(std::out_of_range)
        {
            std::cout << "out_of_range exception" << std::endl;
        }

        d1.push_front("cat");
        d1.push_back("dog");
        d1.pop_front();
        d1.pop_back();
    }
}
