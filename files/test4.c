#include <stdio.h>
void devide(double *a, int *n, double *m)
{
    (*n) = 0;
    while ((*n) < (*a))
    {
        (*n)++;
    }
    (*n)--;
    *m = (*a) - (*n);
};

int main()
{
    double a = 3.14, m = 0;
    int n = 0;
    scanf("%lf", &a);
    devide(&a, &n, &m);
    printf("%f=%d+%f", a, n, m);
    return 0;
}