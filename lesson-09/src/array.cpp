#include <iostream>

namespace my
{
template<class T, size_t N>
class Array
{
public:
    Array(const std::initializer_list<T>& init)
    {
        auto it = init.begin();
        for (size_t i = 0; it != init.end() && i < N; ++i, ++it)
        {
            data_[i] = *it;
        }
    }
    T& operator[](size_t i) { return data_[i]; }
private:
    T data_[N];
    const size_t size_ = N;
};

} // namespace my

int main()
{
    {
        my::Array<std::string, 5> arr = {"cat", "dog"};
        for (size_t i = 0; i < 5; ++i)
        {
            std::cout << "[" << arr[i] << "]" << std::endl;
        }
    }
    {
        my::Array<std::string, 3> arr = {"cat", "dog", "bull", "snake", "bird"};
        for (size_t i = 0; i < 5; ++i)
        {
            std::cout << "[" << arr[i] << "]" << std::endl;
        }
    }
}
