#include <stdio.h>

enum week
{
    mon, // 赋第一个为0，依次递增
    tue, // 用逗号隔开，枚举量不能相同
    wed,
    thu,
    fri,
    sat,
    sun // 最后一个枚举量不用逗号
};

enum year
{
    spring = 1, // 若手动赋值第一个为n，则从n依次递增
    summer,
    autumn,
    winter
};

int main()
{
    printf("%d %d\n", mon, thu);
    printf("%d %d", spring, autumn);
    return 0;
}