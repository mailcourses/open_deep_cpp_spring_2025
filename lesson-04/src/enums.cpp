#include <iostream>

enum COLOUR {
    CLR_RED,
    CLR_YELLOW,
    CLR_BLACK,
    CLR_NONE
};

namespace HttpCodeNamespace
{

enum HTTP_CODE {
    HTTP_OK,
    HTTP_NOT_FOUND,
    HTTP_INTERNAL_SERVER_ERROR,
    HTTP_NONE
};

} // namespace HttpCodeNamespace

enum class Colour
{
    RED,
    YELLOW,
    BLACK,
    NONE
};

enum class HttpCode
{
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500,
    NONE = 0
};

union Colour32
{
    uint32_t code; // RGBA FF000000
    struct {
        uint8_t red, green, blue, alpha;
    } rgba;
};

union Unknown
{
    uint32_t a;
    double b;
    char c;
};

int main()
{
    {
        COLOUR sofa_colour = CLR_RED;
        HttpCodeNamespace::HTTP_CODE code = HttpCodeNamespace::HTTP_NOT_FOUND;
    }

    {
        Colour wall_colour = Colour::RED;
        HttpCode code = HttpCode::NOT_FOUND;
    }

    {
        Colour32 button_colour;
        button_colour.code = 0x00FF00FF;
        std::cout << "code: " << button_colour.code << std::endl;
        std::cout << "red: " << static_cast<uint32_t>(button_colour.rgba.red) << std::endl;
        std::cout << "green: " << static_cast<uint32_t>(button_colour.rgba.green) << std::endl;
        std::cout << "blue: " << static_cast<uint32_t>(button_colour.rgba.blue) << std::endl;
    }

    {
        Unknown unknown;
        unknown.a = 100500;

        //...
        std::cout << "unknown char = " << unknown.c << std::endl;
    }
}
