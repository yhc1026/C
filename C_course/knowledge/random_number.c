#include <stdio.h>
#include <time.h>
int main()
{
    int b = time(NULL);
    printf("%d\n", b);
    srand((unsigned int)time(NULL));
    int a = rand();
    printf("%d", a);
    return 0;
}