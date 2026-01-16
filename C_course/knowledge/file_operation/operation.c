// fputc,fgetc,fputs,fgets:将字符/字符串输入一个流/输出一个流
// fputc 接受两个参数：要写入的字符/字符串，文件操作的指针
// fgetc 接受一个参数：文件操作的指针，并返回一个整型（字符的ASCII码），如果读到文件末尾或者读取失败，则返回EOF
// fputs接受两个参数：需要写入的字符串的地址，文件操作的指针。将字符串写入指定文件
// fgets 接受三个参数：一个用于存放读取到的字符串的数组地址，读取的字符串长度（n-1），文件操作的指针。读取文件中第一行的字符串，存入指定的数组中
#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    fputc('a', pf); // 将字符b写入word.txt文件
    fputc('b', pf);
    fputc('c', pf);
    fputc('d', pf);
    fputc('e', pf);
    return 0
}

#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    int ch = fgetc(pf);
    printf("%c\n", ch);
    return 0;
}

#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    fputs("hello, world", pf); // 将“hello，world写入pf所指的文件内
    char arr[10] = {0};
    return 0
}

#include <stdio.h>
int main()
{
    FILE *pf = fopen("word.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    fgets(arr, 10, pf);
    printf("%s", arr);
    return 0;
}
