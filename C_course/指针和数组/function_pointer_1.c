#include <stdio.h>

int test(int x, int y)
{
    return x + y;
}

int main()
{
    int (*pf)(int x, int y) = &test; // 声明一个指针变量，指向函数test()，"int(int x, int y)"指的是pf指向的函数类型，"&(test)"代表取出函数test()的地址，也可写为"test"或者“&test”
    int t = (*pf)(1, 2);             // 使用t接收函数返回的参数，解引用pf得到test函数本身(不解引用也可以正常运行），(1, 2)代表给函数test()传参1和2
    printf("%d", t);
    return 0;
}