#include <stdio.h>

int Add(int a, int b)
{
    return (a + b);
}

int Sub(int a, int b)
{
    return (a - b);
}

int Mul(int a, int b)
{
    return (a * b);
}

int Div(int a, int b)
{
    return (a / b);
}

int function(int (*p)(int a, int b), int a, int b)
{
    int num = 0;
    num = p(a, b);
    return num;
}

int main()
{
    int t = 0, y = 0, a = 0, b = 0, x = 0, n = 0;
    scanf("%d %d", &a, &b);
    t = function(Add, a, b);
    printf("%d\n", t);
    y = function(Sub, a, b);
    printf("%d\n", y);
    x = function(Mul, a, b);
    printf("%d\n", x);
    n = function(Div, a, b);
    printf("%d", n);
    return 0;
}