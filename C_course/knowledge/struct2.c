#include <stdio.h>

struct name
{
    char first;
    char last;
};

struct that_man
{
    struct name name;
    int age;
};

void modify_name(struct name *p)
{
    p->first = 'y';
    p->last = 'h';
}

void modify_man(struct that_man *p)
{
    p->age = 19;
}

int main()
{
    struct name name;
    struct that_man man;
    modify_name(&name);
    modify_man(&man);
    printf("first name is %c and he is %d years old.", name.first, man.age);
    return 0;
}