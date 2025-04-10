#include <iostream>

static void sum2(int a, int b)
{
}

/* Небезопасно, совсем не безопасно.
int* foo()
{
    int tmp;
    return &tmp;
}
*/

using Obj = char;

struct Retriever
{
    Retriever(const std::string& model_name) : model_name_(model_name), int_ptr_(new int(100)), self(this)
    {
        model_name_ptr_ = &model_name;
    }

    void search() const
    {
        (*model_name_ptr_).size();
        model_name_ptr_->size();
        model_name_ptr_ = nullptr;
        *int_ptr_ = 200;
        //self->int_ptr_ = new int[10];
        self->tmp = 20;
        //tmp = 30;
    }

    void print_result()
    {
    }

    static double calc_distance(const Obj& obj1, const Obj& obj2)
    {
        double distance = 0;
        // ...
        return distance;
    }

    const std::string& model_name_;
    // Указатель на константу.
    mutable std::string const* model_name_ptr_;
    // Константный указатель.
    int * const int_ptr_ = nullptr;
    Retriever * const self = nullptr;
    int tmp = 10;
};

class Foo
{
public:
    Foo()
    {
        ptr = new int[1024];
    }

    ~Foo()
    {
        delete[] ptr;
    }

    void sum(int a, int b)
    {
        /*this->*/attr += a + b;
    }

    static void sum2(int a, int b)
    {
        //attr += a + b;
    }
//private:
public:
    int attr = 0;
    int* ptr = nullptr;
};

struct Boo
{
//public:
    int attr = 0;
};

int main()
{
    Foo foo;
    Boo boo;
    std::cout << "foo.attr = " << foo.attr << std::endl;
    std::cout << "boo.attr = " << boo.attr << std::endl;

    {
        //Foo new_foo = foo;
    }

    *foo.ptr;

    Foo::sum2(1, 2);
    sum2(1, 2);

    //Foo::sum(1, 2);
    //
    {
        Retriever rtvr("hello_model");
    }
    {
        std::string model_name("hello_model_v2");
        const Retriever rtvr(model_name);
        rtvr.search();
        //rtvr.print_result();
    }
}
