#define LENGTH 100 // 宏定义LENGTH为100，在全局生效，注意不加分号！！！！！
#include <stdio.h>
int main()
{
    // int LENGTH = 20;   无法改变宏！
    printf("%d\n", LENGTH);
    // printf("%d", "++LENGTH");  ++LENGTH会错误！（因为宏定义无法修改）
    return 0;
}