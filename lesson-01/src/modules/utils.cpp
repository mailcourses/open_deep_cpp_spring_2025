module;

export module mutils;

int mult(int a, int b)
{
    return a * b;
}

export int square(int n)
{
    return mult(n, n);
}

export
{
    void foo() {}
    void boo() {}
};

export namespace education
{
    void learn() {}
};

