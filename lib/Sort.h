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





/* 基数排序 - 次位优先 */

/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10

/* 桶元素结点 */
typedef struct ToNode *PtrToNode;
struct ToNode {
    int key;
    ToNode* next;
};

/* 桶头结点 */
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit ( int X, int D ){ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;

    for (i=1; i<=D; i++) {
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

void LSDRadixSort( int A[],int N){ /* 基数排序 - 次位优先 */
    int D, Di, i;
    Bucket B;
    PtrToNode tmp, p, List = NULL;

    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
        B[i].head = B[i].tail = NULL;
    for (i=0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
        tmp = (PtrToNode)malloc(sizeof(struct ToNode));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    /* 下面开始排序 */
    for (D=1; D<=MaxDigit; D++) { /* 对数据的每一位循环处理 */
        /* 下面是分配的过程 */
        p = List;
        while (p) {
            Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
            /* 从List中摘除 */
            tmp = p; p = p->next;
            /* 插入B[Di]号桶尾 */
            tmp->next = NULL;
            if (B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else {
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }
        /* 下面是收集的过程 */
        List = NULL;
        for (Di=Radix-1; Di>=0; Di--) { /* 将每个桶的元素顺序收集入List */
            if (B[Di].head) { /* 如果桶不为空 */
                /* 整桶插入List表头 */
                B[Di].tail->next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL; /* 清空桶 */
            }
        }
    }
    /* 将List倒入A[]并释放空间 */
    for (i=0; i<N; i++) {
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        free(tmp);
    }
}

void MSD(int A[], int L, int R, int D )
{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
    int Di, i, j;
    Bucket B;
    PtrToNode tmp, p, List = NULL;
    if (D==0) return; /* 递归终止条件 */

    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
        B[i].head = B[i].tail = NULL;
    for (i=L; i<=R; i++) { /* 将原始序列逆序存入初始链表List */
        tmp = (PtrToNode)malloc(sizeof(struct ToNode));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    /* 下面是分配的过程 */
    p = List;
    while (p) {
        Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
        /* 从List中摘除 */
        tmp = p; p = p->next;
        /* 插入B[Di]号桶 */
        if (B[Di].head == NULL) B[Di].tail = tmp;
        tmp->next = B[Di].head;
        B[Di].head = tmp;
    }
    /* 下面是收集的过程 */
    i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
    for (Di=0; Di<Radix; Di++) { /* 对于每个桶 */
        if (B[Di].head) { /* 将非空的桶整桶倒入A[], 递归排序 */
            p = B[Di].head;
            while (p) {
                tmp = p;
                p = p->next;
                A[j++] = tmp->key;
                free(tmp);
            }
            /* 递归对该桶数据排序, 位数减1 */
            MSD(A, i, j-1, D-1);
            i = j; /* 为下一个桶对应的A[]左端 */
        }
    }
}

void MSDRadixSort(int A[],int N)
{ /* 统一接口 */
    MSD(A, 0, N-1, MaxDigit);
}











#endif