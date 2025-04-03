[[gnu::fastcall]]
void foo1(int a, int b, int c, int d, int e, int f, int g)
{
}

void foo2(int a, int b, int c, int d, int e, int f, int g)
{
}

void boo1()
{
    foo1(1, 2, 3, 4, 5, 6, 7);
}

void boo2()
{
    foo2(1, 2, 3, 4, 5, 6, 7);
}
