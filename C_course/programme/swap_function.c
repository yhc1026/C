#include <stdio.h>
void swap();

int main()
{
    int a = 0, b = 0, c = 0;
    int *pa = &a, *pb = &b, *pc = &c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        swap(pa, pb);
    }
    if (a > c)
    {
        swap(pa, pc);
    }
    if (b > c)
    {
        swap(pb, pc);
    }
    printf("%d %d %d", c, b, a);
    return 0;
}

void swap(int *a, int *b)
{
    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}