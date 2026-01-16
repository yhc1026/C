// strcat：将arr2衔接在arr1之后

#include <stdio.h>

void my_strcat(char *arr1, char *arr2)
{
    while (*arr1 != '\0')
    {
        arr1++;
    }
    while (*arr2 != '\0')
    {
        *arr1 = *arr2;
        arr1++;
        arr2++;
    }
}

int main()
{
    char arr1[10] = "abc";
    char arr2[10] = "def";
    my_strcat(arr1, arr2);
    printf("%s", arr1);
    return 0;
}