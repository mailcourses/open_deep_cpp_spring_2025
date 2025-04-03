#include <iostream>

volatile bool flag = false;

int thread_processing()
{
    //...
    flag = true;
    return 0;
}

int main()
{
    while (!flag); // while (true);
    // .... обработка данных
}
