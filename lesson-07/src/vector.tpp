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
