#include <iostream>
#include <iterator>
#include <numeric> // std::accumulate

namespace my
{

template<typename T>
class array_iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    array_iterator(T* data) : ptr_(data) {}
    array_iterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    bool operator==(const array_iterator<T>& rhs)
    {
        return ptr_ == rhs.ptr_;
    }

    bool operator!=(const array_iterator<T>& rhs)
    {
        return ptr_ != rhs.ptr_;
    }

    T operator*()
    {
        return *ptr_;
    }
private:
    T* ptr_;
};

template<typename T, size_t size>
class array
{
public:
    array(std::initializer_list<T> init)
    {
        auto it = init.begin();
        for(size_t i = 0; i < size && it != init.end(); ++i, ++it)
        {
            data[i] = *it;
        }
    }

    array_iterator<T> begin()
    {
        return array_iterator<T>(data);
    }

    array_iterator<T> end()
    {
        return array_iterator<T>(data + size);
    }
private:
    T data[size];
};

} // namespace my

int main()
{
    my::array<int32_t, 4> arr = {5, 3, 8, 1};
    auto it = arr.begin();
    while(it != arr.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    auto sum = std::accumulate(std::begin(arr), std::end(arr), 0);
    std::cout << "sum of array is " << sum << std::endl;
}
