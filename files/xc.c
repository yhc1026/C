#include <stdio.h>
float average10(float a[10])
{
    float aver = 0.0;
    float sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &a[i]);
        sum += a[i];
    }
    int t = 0;
    float min = a[0], max = a[0];
    while (t < 9)
    {
        if (a[t + 1] < min)
        {
            min = a[t + 1];
        }
        if (a[t + 1] > max)
        {
            max = a[t + 1];
        }
        t++;
    }

    aver = (sum - min - max) / 8;
    return aver;
}

int main()
{
    float a[10] = {};
    float aver = 0.0;
    aver = average10(a);
    printf("%.3lf", aver);
    return 0;
}