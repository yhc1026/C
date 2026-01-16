#include <stdio.h>
int main()
{
    int i = 0, j = 2, flag = 1;
    srand(time(NULL));
    for (j = 2; j < (rand()); j++)
    {
        flag = 1;
        for (i = 2; i < j; i++)
        {
            int t = 0;
            t = j % i;
            if (t == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d,", j);
        }
    }
    return 0;
}