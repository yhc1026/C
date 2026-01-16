// 串的模式匹配算法
// 求一个子串在主串中的位置，返回位置，若不存在则返回0

// 算法1：BF算法，把主串中的字符依次比较

int BF(Sstring S, Sstring T)
{
    int i = 1, j = 1;
    while (i <= S.size && j <= L.size)
    {
        if (S.arr[i] != L.arr[j])
        {
            int t = j - 1;
            j = 0;
            i = i - t;
        }
        i++;
        j++;
    }
    if (i > S.size)
    {
        return 0;
    }
    return i - T.size;
}

//算法2：KMP算法，主串指针i不再回溯，利用next[j]数组判断j回溯的位置