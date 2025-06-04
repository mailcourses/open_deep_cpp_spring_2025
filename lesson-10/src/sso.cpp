#include <string>
#include <iostream>

namespace my
{

class string
{
public:
    string(const char* str)
    {
        size_t n = strlen(str);
        std::cout << "sizeof(data_) is " << sizeof(data_) << ", n = " << n << std::endl;
        if (n >= MAX_BUF_SIZE) {
            std::cout << "large string" << std::endl;
            data_.large.ptr_ = new char[n * 2];
            data_.large.capacity_ = n * 2;
            data_.large.size_ = n;
            std::memcpy(data_.large.ptr_, str, n);
            data_.large.ptr_[n+1] = '\0';
        } else {
            std::cout << "small string" << std::endl;
            std::memcpy(data_.small.buffer, str, n);
            data_.small.is_small_flag = true;
            data_.small.buffer[n] = '\0';
        }
    }

    char operator[](size_t i)
    {
        if (data_.small.is_small_flag) {
            return data_.small.buffer[i];
        } else {
            return *(data_.large.ptr_+i);
        }
    }
private:
    static constexpr size_t MAX_BUF_SIZE = 23; // 22 символа + 1 терминальный символ
    union Data {
        struct {
            size_t size_ = 0;
            size_t capacity_ = 0;
            char* ptr_ = nullptr;
        } large;

        struct {
            char buffer[MAX_BUF_SIZE];
            uint8_t is_small_flag = false;
        } small;
    } data_ {};
};

} // namespace

int main()
{
    my::string s1("small");
    my::string s2("vvvvvvvvvery large string");
    std::cout << s1[1] << " : " << s2[1] << std::endl;
    return 0;
}
