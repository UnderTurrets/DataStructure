#ifndef __Sort_h__
#define __Sort_h__

#include "authority.h"
#include "Heap.h"


//冒泡排序
template<typename T>
vector<T> BubbleSort(vector<T> X);

//插入排序
template<typename T>
vector<T> InsertionSort(vector<T> X);

//希尔排序
template<typename T>
vector<T> ShellSort(vector<T>X);


//堆排序
template<typename T>
vector<T> HeapSort(vector<T>X);


/* 归并排序 - 递归实现 */
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
template<typename T>
void Merge(vector<T>&A, vector<T>TmpA, int L, int R, int RightEnd );

template<typename T>
void Msort( vector<T>&A, vector<T>TmpA, int L, int RightEnd );

template<typename T>
vector<T> MergeSortRecurrence( vector<T>A);

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */
/* length = 当前有序子列的长度*/
template<typename T>
void Merge_pass(vector<T>&A, vector<T>TmpA, int N, int length );

template<typename T>
vector<T> MergeSortCommon( vector<T>A);















#endif