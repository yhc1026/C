#include <stdio.h>
#include <string.h>
int main()
{
    char arr1[] = "abc", arr2[] = "def";
    // char *p1 = arr1, *p2 = arr2;
    strcpy(arr1, arr2); // string copy,拷贝arr2到arr1,括号中放的是两个地址（指针）
    printf("%s\n", arr1);

    int t = strlen(arr1); // string length, 计算arr1的长度，不包括空字符
    printf("%d\n", t);

    strcpy(arr1, "abc");
    strcat(arr1, arr2); // string concatenation，将arr2的内容加到arr1的末尾
    printf("%s\n", arr1);

    strcpy(arr1, "abc");
    strcpy(arr2, "def");
    int n = strcmp(arr2, arr1); // string compare, 根据arr1和arr2的大小，返回小于、等于、大于0的值
    printf("%d\n", n);          // 由于 "def"在字典顺序中大于"abc”，因此strcmp函数返回一个大于0的值。
    return 0;
}