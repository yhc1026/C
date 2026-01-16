char *level(int tour)
{
    if (tour == 0)
    {
        return "Typical Otaku";
    }
    else if (tour <= 2)
    {
        return "Eye Opener";
    }
    else if (tour <= 4)
    {
        return "Young Traveller";
    }
    else if (tour <= 7)
    {
        return "Excellent Traveller";
    }
    else
    {
        return "Senior Traveller";
    }
}
int main()
{
    int M, a[10][8], tour[10] = {0};
    int i, j;
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < 8; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (a[i][j] != 0)
            {
                tour[i] += 1;
            }
        }
        printf("%s\n", level(tour[i]));
    }
    return 0;
}
