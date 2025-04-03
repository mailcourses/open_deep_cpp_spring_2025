#include <iostream>

enum class HttpCode
{
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

[[nodiscard("You should not ignore returned value")]]
HttpCode get_source( [[maybe_unused]] const std::string& url )
{
    // ...
    return HttpCode::OK;
}

int main()
{
    [[maybe_unused]] HttpCode code = get_source("https://vk.com/");
    if (code == HttpCode::OK) [[likely]]
    {
        // ...
    }
    else if (code == HttpCode::NOT_FOUND) [[unlikely]]
    {
    }
    else if (code == HttpCode::INTERNAL_SERVER_ERROR)
    {
    }
    //get_source("https://vk.com/");
}
