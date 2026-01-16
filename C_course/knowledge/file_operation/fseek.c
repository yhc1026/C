// 定位文件指针，可以定位到文本的任意位置
// 接收三个参数：文件操作指针，偏移量，从哪里开始偏移。其中SEEK_SET代表从头开始；SEEK_END代表从末尾开始；SEEK_CUR代表从当前位置开始.
// 偏移量大于00往后跳，小于0往前跳
#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "r");
    int arr = fgetc(pf);
    fseek(pf, 3, SEEK_SET);
    arr = fgetc(pf);
    printf("%c\n", arr);
    fseek(pf, -2, SEEK_CUR);
    arr = fgetc(pf);
    printf("%c", arr);
    return 0;
}