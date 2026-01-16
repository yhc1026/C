#include <stdio.h>
void swap();

int main()
{
    int a = 0, b = 0, c = 0;
    int *pa = &a, *pb = &b, *pc = &c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
    {
        printf("等边三角形");
        return main();
    }
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
    if (a + b <= c)
    {
        printf("不是三角形");
        return main();
    }
    if (a == b || b == c)
    {
        printf("等腰三角形");
        return main();
    }
    else
    {
        printf("普通三角形");
    }
    return main();
}

void swap(int *a, int *b)
{
    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}