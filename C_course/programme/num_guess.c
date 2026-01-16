#include <stdio.h>
void menu();
void game();
void replay();
void sure();

int main()
{
    menu();
    game();
    replay();
    return 0;
}

void menu()
{
    int a = 0;
    printf("press 1 to start\n");
    printf("press 2 to exit\n");
    scanf("%d", &a);
    if (a == 0)
    {
        return 0;
    }
}

void game()
{
    srand((unsigned int)time(NULL));
    int num = (rand()) / 100;
    for (;;)
    {
        printf("\n");
        int x = 0;
        printf("guess a number:");
        scanf("%d", &x);
        if (x < num)
        {
            printf("guess a bigger one");
        }
        if (x > num)
        {
            printf("guess a smaller one");
        }
        if (x == num)
        {
            printf("you are right! \n");
            return replay();
        }
    }
}

void replay()
{
    char n = 0;
    printf("press y to replay\n");
    printf("press n to exit\n");
    getchar();
    scanf("%c", &n);
    if (n == 'y')
    {
        return game();
    }
    if (n == 'n')
    {
        return sure();
    }
}

void sure()
{
    char m = 0;
    printf("are you sure?\n");
    printf("sure: y\nnot sure: n\n");
    getchar();
    scanf("%c", &m);
    if (m == 'y')
    {
        return 0;
    }
    if (m == 'n')
    {
        return game();
    }
}