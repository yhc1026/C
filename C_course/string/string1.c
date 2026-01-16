// 串当中的每个元素都是字符
// S="a b c d e f" S为串名，每个字母是串值，长度为串长，如果没有元素，叫做空串
// 子串：一个串中任意连续的字符组成的子序列被称为子串
// 主串：包含子串的叫做主串
// 字符位置：字符在序列中的需要被称为字符位置
// 子串位置：子串当中的首字符出现在主串当中的位置
// 空格串：有一个或多个空格组成的串，与空串不同
// 串相等：当且仅当两个串长度相等，并且每个对应位置上的字符都相等，这两个串才是相等的（所有空串都相等）

// 顺序字符串
#define MAX 250

typedef struct SSTRING
{
    char arr[MAX + 1]; // 从一号位置向后存储，这样在一些算法中更加便利
    int size;
} Sstring;

// 特殊的链式存储结构：一个节点中放入多个字符
#define TRUNKSIZE 10

typedef struct Chunk
{
    char arr[TRUNKSIZE];
    struct String *next;
} chunk;

typedef struct LSTRING
{
    chunk *head;
    chunk *tail;
    int curlen;
} Lstring;