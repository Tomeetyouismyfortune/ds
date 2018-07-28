#ifndef SORT_H
#define SORT_H

#define QUICK_SORT 0
#define HEAP_SORT 1
#define MERGE_SORT 2
#define SHELL_SORT 3

/* SqList第0位为哨兵，从1开始计数 */
typedef int *SqList;

/* 排序函数，默认使用快排 */
int Sort(SqList &l, int len);
int Sort(SqList &l, int len, int solution);

/* 插入排序 */

// 直接插入排序
int InsertSort(SqList &l, int len);

// 希尔排序

/* 快速排序 */

// 冒泡排序
int BubbleSort(SqList &l, int len);

// 快速排序
int QuickSort(SqList &l, int len);

/* 选择排序 */

// 简单选择
int SelectSort(SqList &l, int len);

// 堆排序
int HeapSort(SqList &l, int len);

/* 归并排序 */

// 二路归并排序
int MergeSort(SqList &l, int len);

#endif