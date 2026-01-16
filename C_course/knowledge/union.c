
#include <stdio.h>
#include <string.h>
union shirt
{
    int prize;
    char brand[20];
    int size;
};

int main()
{
    union shirt nike = {0};
    strcpy(nike.brand, "nike");
    printf("%s", nike.brand);
    return 0;
}
