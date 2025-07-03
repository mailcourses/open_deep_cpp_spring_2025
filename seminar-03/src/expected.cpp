#include <iostream>
#include <vector>
#include <expected>


enum class parse_error
{
    invalid_input,
    overflow
};


auto parse_number(std::string_view& str) -> std::expected<double, parse_error>
{
    const char* begin = str.data();
    char* end;
    double retval = std::strtod(begin, &end);
    if (begin == end)
        return std::unexpected(parse_error::invalid_input);
    else if (std::isinf(retval))
        return std::unexpected(parse_error::overflow);
    str.remove_prefix(end - begin);
    return retval;
}

int main()
{
    std::vector<std::string> strs = {"12.3", "abcd", "11111111111111111111111111111111111111111111111111.2"};
    for (auto& str : strs)
    {
        auto str_v = std::string_view(str.data(), str.size());
        auto res = parse_number(str_v);
        std::cout << "str: " << str << ", value = " << std::boolalpha << res.has_value() << std::endl;
    }

    {
        std::string str = "123.2 asdasd 32434 inf";
        auto str_v = std::string_view(str.data(), str.size());
        while (!str_v.empty())
        {
            auto res = parse_number(str_v);
            std::cout << "str: " << str << ", value = " << std::boolalpha << res.has_value() << std::endl;
            std::cout << str_v << std::endl;
            std::cout << str << std::endl;
        }
    }
}
