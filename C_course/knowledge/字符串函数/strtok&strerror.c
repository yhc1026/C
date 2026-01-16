// strtok函数负责分割字符串，了解即可
// strerror函数接受一个错误码，并返回错误码表示的相关错误
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    while (i < 100)
    {
        printf("%s\n", strerror(i));
        i++;
    }
    return 0;
}