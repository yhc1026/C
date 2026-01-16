// 插入排序算法
void insertsort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int end = i - 1;
        int tmp = a[i];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}