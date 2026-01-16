#include <stdio.h>
#include <string.h>

struct stu // 定义一个stu类型的结构体（其实真正的类型叫做 “struct stu” ）
{
    int age;
    int num;
    char name[];
};

// 写法1：这种写法，更加易懂，但啰嗦,浪费空间
// void modify_struct(struct stu *s) // 接收main函数传过来的“stu结构体”类型的变量s的地址
// {
//     (*s).age = 19; // 解引用stu结构体类型的变量s的地址，找到结构体类型的变量s中，整型变量age，将10赋值给age
//     (*s).num = 1;  // 解引用stu结构体类型的变量s的地址，找到结构体类型的变量s中，整型变量num，将1赋值给num
//     strcpy((*s).name, "yhc");
// }

// 写法2：这种写法，更加简便，但抽象
void modify_struct(struct stu *p)
{
    p->age = 19; //(*s).age = 19
    p->num = 1;  //(*s).num = 1;
    strcpy(p->name, "frys");
}

void prt_struct(struct stu *t)
{
    printf("姓名：%s  学号：%d  年龄：%d", (*t).name, (*t).num, (*t).age);
}

int main()
{
    struct stu s = {0}; // 声明了一个 “struct stu” 类型的变量s
    modify_struct(&s);  // 将“struct stu”类型的变量s的地址传给modify函数
    prt_struct(&s);
    return 0;
}