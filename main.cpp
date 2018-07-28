#include "include/stdafx.h"

int main()
{
    int len = 0;
    printf_s("please input:");
    scanf_s("%d", &len);
    SqList l = new int[len + 1];
    l[0] = len;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= len; ++i)
    {
        l[i] = rand()%len;
        printf_s("%d", l[i]);
    }
    printf_s("\n");
    Sort(l, len, QUICK_SORT);
    for (int i = 1; i <= len; ++i)
    {
        printf_s("%d", l[i]);
    }
    return 0;
}