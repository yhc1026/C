#include <stdio.h>

char my_strstr(char *arr1, char *arr2)
{
    while(arr2!='\0')
    {
        while(arr1!=arr2)
        {
            arr1++;
        }
        arr1++;
        arr2++;
    }
    
    
}

int main()
{
    char arr1[10] = "abcdefghk";
    char arr2[10] = "def";
    printf("%s", my_strstr(arr1, arr2));
    return 0;
}