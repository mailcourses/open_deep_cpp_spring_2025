#include <iostream>
#include <system_error>

enum class HttpCode
{
    OK = 200,
    NO_CONTENT = 202,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const noexcept override
    {
        switch(code) {
            case 200:
                return "ok";
            case 202:
                return "no content";
            case 404:
                return "not found";
            case 500:
                return "internal server error";
            default:
                return "unknown error";
        }
    }
};

std::error_code make_error_code(HttpCode code)
{
    static HttpCategory instance;
    return std::error_code(static_cast<int>(code),
                           instance);
}

[[nodiscard("You should not ignore std::error_code for download function!")]]
std::error_code download(const std::string& url)
{
    if (url == "https://vk.com") {
        // ...
        return make_error_code(HttpCode::OK);
    }
    if (url == "https://forbidden.com") {
        // ...
        return make_error_code(HttpCode::NOT_FOUND);
    }
    else {
        // ...
        return make_error_code(HttpCode::INTERNAL_SERVER_ERROR);
    }
}

int main()
{
    {
        auto urls = {"https://vk.com", "https://forbidden.com", "http://unknown.org"};
        for (auto url: urls)
        {
            auto error_code = download(url);
            if (error_code)
            {
                std::cerr << error_code << std::endl;
                std::cerr << error_code.message() << std::endl;
            }
        }
    }
    return 0;
}
