// strlen：计算一个字符串长度

#include <stdio.h>

int my_strlen(char *p)
{
    int cnt = 0;
    for (; *p != '\0'; p++)
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    printf("%d", my_strlen(abcd));
    return 0;
}
