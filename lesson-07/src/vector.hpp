#pragma once
#include <iostream>

namespace my
{

template<typename T>
class vector
{
public:
    vector() = default;
    vector(size_t capacity) : capacity_(capacity)
    {
        data_ = new T[capacity_];
    }

    vector<T> operator+(const vector<T>& rhs);
private:
    T* data_ = nullptr;
    size_t capacity_ = 0;
    size_t size_ = 0;
};

#include "vector.tpp"

/*
template<class T>
vector<T>
vector<T>::operator+(const vector<T>& rhs)
{
    vector<T> tmp(std::max(size_, rhs.size_));
    for (size_t i = 0; i < rhs.size_; ++i)
    {
        tmp.data_[i] = data_[i] + rhs.data_[i];
    }
    return tmp;
}
*/

} // namespace my
