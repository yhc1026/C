#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    char arr[10] = {0};
    fgets(arr, 10, pf);
    printf("%s", arr);
    return 0;
}
