// fopen函数，接受两个参数，文件名和打开方式
#include <stdio.h>
int main()
{
    FILE *pf = fopen("C:\\Users\\47894\\Desktop\\word2.docx", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    return 0;
}