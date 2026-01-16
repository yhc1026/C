#include <stdio.h>

void Exit()
{
    return 0;
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int main()
{
    int a = 0, b = 0;
    int (*p1)(int, int);
    printf("输入两个数字：");
    scanf("%d %d", &a, &b);
    printf("选择相应操作（z，a，b，c，d）：");
    int t = 0;
    scanf("%d", &t);
    int ret = 0;
    printf("%d", ret);
    return 0;
}