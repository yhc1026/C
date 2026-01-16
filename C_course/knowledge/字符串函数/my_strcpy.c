// strcpy：比较arr1和arr2大小，若前者大，返回大于零的整数，相等，返回0，小于，返回小于零的整数
// 比较方法：比较对应位置的大小，若比较两个\0，则表明两个字符串一样大

#include <stdio.h>

void my_strcpy(char *arr1, char *arr2)
{
    do
    {
        *arr2 = *arr1;
        arr1++, arr2++;
    } while (*arr1 != '\0');
}

int main()
{
    char arr1[20] = "abc";
    char arr2[20] = {0};
    arr2[4] = 'e';
    my_strcpy(arr1, arr2);
    printf("%s", arr2);
    return 0;
}