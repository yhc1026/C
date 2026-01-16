// fopen函数，接受两个参数，文件名和打开方式
#include <stdio.h>
int main()
{
    FILE *pf = fopen("C:\\Users\\47894\\Desktop\\word2.docx", "w"); // 打开文件data.txt，只读文件，若打开失败，则返回空指针;
    if (pf == NULL)                                                 // 相同路径可以忽略路径，不同路径则要加上路径
    {
        perror("fopen");
        return 1;
    }
    return 0;
}