#include <iostream>
#include <memory>

struct A
{
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

int main()
{
    //A* p1 = new A;
    std::shared_ptr<A> sp1(new A);
    //A* p3 = p1;
    std::shared_ptr<A> sp3 = sp1;

    std::unique_ptr<A> up1(new A);
    std::unique_ptr<A> up2 = std::move(up1);
    //delete p1;

    A* p2 = static_cast<A*>(malloc(sizeof(A)*10));
    p2 = new (p2) A;
    free(p2);
    return 0;
}
