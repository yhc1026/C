// 静态顺序表   给小了不够用，给大了浪费，因此推荐动态的

#define N 10

#include <stdio.h>

// struct Seqlist
//{
//    int a[N]; // 表中一般使用宏定义大小
//    int size = 0;
//};

// 因此推荐动态的顺序表

typedef struct Seqlist
{
    int *b[N - 1] = {0};
    int size;     // 数据个数
    int capacity; // 总空间（数据个数可变，总空间不可变，且数据个数必须小于等于总空间
} SQ;

void start(SQ *sq) // 初始化
{
    sq->b[size] = (int *)malloc(sizeof(int));
    sq->size = N;
    sq->capacity = N;
}

void destroy(SQ *sq) // 销毁
{
    free(sq->b);
    sq->b = NULL;
    sq->size = 0;
    sq->capacity = 0;
}

void pushback(SQ *sq, int x); // 插入数据 尾插法  x为增加的数据数值
{
    sq->b[sq->size++] = x;
}

void pushhead(SQ *sq, int x); // 插入数据 头插法
{
}

void popback(SQ *sq); // 删除数据 尾删法
{
}

void pophead(SQ *sq); // 删除数据 头删法
{
}

int main()
{
    SQ sq = {NULL, 0, 0};
    start(&sq);
    pushback(&sq, 1);
    printf("%d\n", sq.b[10]);
    destroy(&sq);
    printf("%p\n", sq.b);
    return 0;
}
