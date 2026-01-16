#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    printf("%d除3余", a);
    switch (a % 3)
    {
    case 0:
    {
        printf("0");
    }
    break;
    case 1:
    {
        printf("1");
    }
    break;
    case 2:
    {
        printf("2");
    }
    break;
    }
    return 0;
}