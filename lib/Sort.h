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

//快速排序
template<typename T>
void Qsort( vector<T> &A, int Left, int Right );

template<typename T>
vector<T> QuickSort( vector<T>A );

/*基数排序*/
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10

//一个桶中每个元素的定义
typedef struct ToNode *PtrToNode;
struct ToNode;

//一个桶的定义
struct HeadNode;
typedef struct HeadNode Bucket[Radix];

/* 基数排序 - 次位优先 */
// 获得元素X的第D位数字
int GetDigit ( int X, int D );

vector<int> LSDRadixSort(vector<int> input);

/* 基数排序 - 主位优先 */
// 核心递归函数: 对input[L]...input[R]的第D位数进行排序
void MSD(vector<int> &input, int L, int R, int D );

vector<int> MSDRadixSort(vector<int> input);











#endif