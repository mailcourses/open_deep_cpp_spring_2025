#include <iostream>
#include <vector>
#include <functional>

using MoveFunction = std::function<void (int& x, int& y)>;

void moveLeft(int &x, int &y)
{
    std::cout << "moveLeft function" << std::endl;
}

struct RightMover
{
    void operator()(int& x, int& y)
    {
        std::cout << "RightMover functor" << std::endl;
    }
};

int main()
{
    RightMover right_mover;
    std::vector<MoveFunction> trajectory =
    {
        [](int& x, int& y) { std::cout << "lambda" << std::endl; },
        moveLeft,
        right_mover
    };
    int x = 10;
    int y = 20;
    for (MoveFunction & move : trajectory)
    {
        move(x, y);
    }
}
