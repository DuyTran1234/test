/*
    Cài đặt chương trình tìm số thứ N trong dãy Fibonacci.
*/
#include <iostream>

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int x1 = 1, x2 = 1;
    int x = x1 + x2;
    int i = 3;
    while (i <= n)
    {
        x = x1 + x2;
        x1 = x2;
        x2 = x;
        ++i;
    }
    return x;
}

int main()
{
    std::cout << "f(10): " << fibonacci(10) << "\n";
}