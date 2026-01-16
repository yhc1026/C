#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    char arr1[21] = {'0'}, arr2[21] = "********************";
    int i = 0;
    scanf("%[^\n]s", arr1);
    for (i = 0; i < 10; i++)
    {
        arr2[i] = arr1[i];
        arr2[19 - i] = arr1[19 - i];
        int j = 0;
        for (j = 0; j < 21; j++)
        {
            printf("%c", arr2[j]);
        }
        printf("\n");
        Sleep(100);
    }
    return 0;
}
