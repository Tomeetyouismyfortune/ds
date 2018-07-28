#include "include/sort.h"

/* 排序函数，默认使用快排 */
int Sort(SqList &l, int len)
{
    Sort(l, len, QUICK_SORT);
    return 0;
}
int Sort(SqList &l, int len, int solution)
{
    switch (solution)
    {
        case QUICK_SORT:
        {
            QuickSort(l, len);
            break;
        }
        case HEAP_SORT:
        {
            HeapSort(l, len);
            break;
        }
        case MERGE_SORT:
        {
            MergeSort(l, len);
            break;
        }
        case SHELL_SORT:
        {
            // TODO
            break;
        }
    }
    return 0;
}

/* 插入排序 */
int InsertSort(SqList &l,int len)
{
    for(int i = 2; i <= len; ++i)
    {
        int j = 0;
        if (l[i] < l[i - 1])
        {
            l[0] = l[i];
            l[i] = l[i - 1];
            for (j = i - 2; l[0] < l[j]; --j)
            {
                l[j + 1] = l[j];
            }
            l[j + 1] = l[0];
        }
    }
    return 0;
}

/* 希尔排序 */
/* int ShellInsert(SqList &l, int len, int dk)
{
    for (int i = 1; i <= dk; ++i)
    {
        for (int )
    }
    return 0;
}
int ShellSort(SqList &l, int len)
{
    
    return 0;
} */

/* 冒泡排序 */
int BubbleSort(SqList &l, int len)
{
    for (int i = 2; i <= len; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (l[j] < l[j + 1])
            {
                l[0] = l[j];
                l[j] = l[j + 1];
                l[j + 1] = l[0];
            }
        }
    }
    return 0;
}

/* 快速排序 */
int Partition(SqList &l, int low, int high)
{
    int t = l[low];
    while (low < high)
    {
        while (low < high && l[high] >= t) --high;
        l[low] = l[high];
        while (low < high && l[low] <= t) ++low;
        l[high] = l[low];
    }
    l[low] = t;
    return low;
}
int QSort(SqList &l, int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(l, low, high);
        QSort(l, low, pivotloc - 1);
        QSort(l, pivotloc + 1, high);
    }
    return 0;
}
int QuickSort(SqList &l, int len)
{
    QSort(l, 1, len);
    return 0;
}

/* 简单选择排序 */
int SelectSort(SqList &l, int len)
{
    int min = 0;
    int m = 0;
    for (int i = 1; i < len; ++i)
    {
        min = l[i];
        m = i;
        for (int j = i; j <= len; ++j)
        {
            if (l[j] < min)
            {
                min = l[j];
                m = j;
            }
        }
        min = l[i];
        l[i] = l[m];
        l[m] = min;
    }
    return 0;
}

/* 堆排序 */
int HeapAdjust(SqList &l, int s, int m)
{
    int t = l[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && l[j] < l[j + 1]) ++j;
        if (t >= l[j]) break;
        l[s] = l[j];
        s = j;
    }
    l[s] = t;
    return 0;
}

int HeapSort(SqList &l, int len)
{
    int t = 0;
    for (int i = len / 2; i > 0; --i)
    {
        HeapAdjust(l, i, len);
    }
    for (int i = len; i > 1; --i)
    {
        t = l[1];
        l[1] = l[i];
        l[i] = t;

        HeapAdjust(l, 1, i - 1);
    }
    return 0;
}

/* 二路归并排序 */
int Merge(SqList &sl, SqList &tl, int i, int m, int n)
{
    int j = 0;
    int k = 0;
    int t = i;
    for (j = m + 1, k = i; i <= m && j <= n; ++k)
    {
        if (sl[i] <= sl[j]) tl[k] = sl[i++];
        else tl[k] = sl[j++];
    }
    while (i <= m)
    {
        tl[k++] = sl[i++];
    }
    while (j <= n)
    {
        tl[k++] = sl[j++];
    }
    for (; t <= n; t++)
    {
        sl[t] = tl[t];
    }
    return 0;
}
int MSort(SqList &sl, SqList &tl, int s, int t)
{
    if (s == t) tl[s] = sl[s];
    else {
        int m = (s + t) / 2;
        MSort(sl, tl, s, m);
        MSort(sl, tl, m + 1, t);
        Merge(sl, tl, s, m, t);
    }
    return 0;
}
int MergeSort(SqList &l, int len)
{
    SqList tl = new int[len + 1];
    MSort(l, tl, 1, len);
    delete[] tl;
    return 0;
}