#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], i, result = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 3 == 0)
            result += a[i];
    }
    printf("%d", result);
}