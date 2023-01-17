#include "Sort.h"


//冒泡排序
template<typename T>
vector<T> BubbleSort(const vector<T> input){
    vector<T>output(input);
    for(int i=output.size()-1;i>=0;i--){
        bool flag=0;
        for(int j=0;j<i;j++){
            if(output[j]>output[j+1]){
                swap(output[j],output[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    return output;
}

//插入排序
template<typename T>
vector<T> InsertionSort(const vector<T> input){
    vector<T>output(input);
    int P, i;
    T Tmp;
    for ( P=1; P<output.size(); P++ ) {
        Tmp = output[P]; /* 取出未排序序列中的第一个元素*/
        for ( i=P; i>0 && output[i-1]>Tmp; i-- )
            output[i] = output[i-1]; /*依次与已排序序列中元素比较并右移*/
        output[i] = Tmp; /* 放进合适的位置 */
    }
    return output;
}

//希尔排序
template<typename T>
vector<T> ShellSort(const vector<T>input){
    vector<T>output(input);
    int Si, D, P, i;
    T Tmp;
    /* 这里只列出一小部分增量 */
    vector<int> Sedgewick = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for ( Si=0; Sedgewick[Si]>=output.size(); Si++ ); /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

    for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] ) {
        for (P = D; P < output.size(); P++) { /* 插入排序*/
            Tmp = output[P];
            for (i = P; i >= D && output[i - D] > Tmp; i -= D) {
                output[i] = output[i - D];
            }
            output[i] = Tmp;
        }
    }
    return output;
}


//堆排序
template<typename T>
vector<T> HeapSort(const vector<T>input){
    vector<T>output;
    MinHeap<T>temp(input);
    for ( int i=0;i<input.size(); i++ ) {
        /* 删除最大堆顶 */
        output.push_back(temp.deleteMin());
    }
    return output;
}


/* 归并排序 - 递归实现 */
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
template<typename T>
void Merge(vector<T>&A, vector<T>TmpA, int L, int R, int RightEnd ){ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;

    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;

    while( L <= LeftEnd && R <= RightEnd ) {
        if ( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }

    while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

template<typename T>
void Msort( vector<T>&A, vector<T>TmpA, int L, int RightEnd ){ /* 核心递归排序函数 */
    int Center;
    if ( L < RightEnd ) {
        Center = (L+RightEnd) / 2;
        Msort( A, TmpA, L, Center );              /* 递归解决左边 */
        Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */
        Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */
    }
}

template<typename T>
vector<T> MergeSortRecurrence( const vector<T>A){ /* 归并排序 */
    vector<T>output(A);
    vector<T>TmpA;int N=output.size();
    TmpA.resize(N);

    if ( TmpA.size()!=0 ) {
        Msort( output, TmpA, 0, N-1 );
    }
    else printf( "空间不足" );
    return output;
}

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */
/* length = 当前有序子列的长度*/
template<typename T>
void Merge_pass(vector<T>A, vector<T>TmpA, int N, int length ){ /* 两两归并相邻有序子列 */
    int i, j;
    for ( i=0; i <= N-2*length; i += 2*length )
        Merge( A, TmpA, i, i+length, i+2*length-1 );
    if ( i+length < N ) /* 归并最后2个子列*/
        Merge( A, TmpA, i, i+length, N-1);
    else /* 最后只剩1个子列*/
        for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}

template<typename T>
vector<T> MergeSortCommon(const  vector<T>A){
    int length;int N=A.size();
    vector<T>TmpA;TmpA.resize(N);
    vector<T>output(A);

    length = 1; /* 初始化子序列长度*/
    if ( TmpA.size()!=0 ) {
        while( length < N ) {
            Merge_pass( output, TmpA, N, length );
            length *= 2;
            Merge_pass( TmpA, output, N, length );
            length *= 2;
        }
    }
    else printf( "空间不足" );
    return output;
}

template<typename T>
T Median3( vector<T>&A, int Left, int Right )
{
    int Center = (Left+Right) / 2;
    if ( A[Left] > A[Center] )
        swap( A[Left], A[Center] );
    if ( A[Left] > A[Right] )
        swap( A[Left], A[Right] );
    if ( A[Center] > A[Right] )
        swap(A[Center], A[Right] );
    /* 此时A[Left] <= A[Center] <= A[Right] */
    swap( A[Center], A[Right-1] ); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return  A[Right-1];  /* 返回基准Pivot */
}

template<typename T>
void Qsort( vector<T> &A, int Left, int Right )
{ /* 核心递归函数 */
        int Pivot, Cutoff, Low, High;
    Cutoff=10;
    if ( Cutoff <= Right-Left ) { /* 如果序列元素充分多，进入快排 */
        Pivot = Median3(A, Left, Right); /* 选基准 */
        Low = Left;
        High = Right - 1;
        while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while (A[++Low] < Pivot);
            while (A[--High] > Pivot);
            if (Low < High) swap(A[Low], A[High]);
            else break;
        }
        swap(A[Low], A[Right - 1]);   /* 将基准换到正确的位置 */
        Qsort(A, Left, Low - 1);    /* 递归解决左边 */
        Qsort(A, Low + 1, Right);   /* 递归解决右边 */
    }else A=InsertionSort(A); /* 元素太少，用简单排序 */
}

template<typename T>
vector<T> QuickSort( vector<T>A ){ /* 统一接口 */
    int N=A.size();
    vector<T>ret(A);
    Qsort( ret, 0, N-1 );
    return ret;
}

/*基数排序*/
//一个桶中每个元素的定义
typedef struct ToNode *PtrToNode;
struct ToNode {
    int key;
    ToNode* next;
};

//一个桶的定义
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

/* 基数排序 - 次位优先 */
// 获得元素X的第D位数字
int GetDigit ( int X, int D ){ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;

    for (i=1; i<=D; i++) {
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

vector<int> LSDRadixSort(const vector<int> input){ /* 基数排序 - 次位优先 */
    vector<int>output(input);
    int D, Di, i;int N=input.size();
    Bucket B;
    PtrToNode tmp, p, List = NULL;

    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
        B[i].head = B[i].tail = NULL;
    for (i=0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
        tmp = (PtrToNode)malloc(sizeof(struct ToNode));
        tmp->key = output[i];
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
    /* 将List倒入output[]并释放空间 */
    for (i=0; i<N; i++) {
        tmp = List;
        List = List->next;
        output[i] = tmp->key;
        free(tmp);
    }
    return output;
}

/* 基数排序 - 主位优先 */
// 核心递归函数: 对input[L]...input[R]的第D位数进行排序
void MSD(vector<int> &input, int L, int R, int D ){
    int Di, i, j;
    Bucket B;
    PtrToNode tmp, p, List = NULL;
    if (D==0) return; /* 递归终止条件 */

    for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
        B[i].head = B[i].tail = NULL;
    for (i=L; i<=R; i++) { /* 将原始序列逆序存入初始链表List */
        tmp = (PtrToNode)malloc(sizeof(struct ToNode));
        tmp->key = input[i];
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
    i = j = L; /* i, j记录当前要处理的input[]的左右端下标 */
    for (Di=0; Di<Radix; Di++) { /* 对于每个桶 */
        if (B[Di].head) { /* 将非空的桶整桶倒入input[], 递归排序 */
            p = B[Di].head;
            while (p) {
                tmp = p;
                p = p->next;
                input[j++] = tmp->key;
                free(tmp);
            }
            /* 递归对该桶数据排序, 位数减1 */
            MSD(input, i, j-1, D-1);
            i = j; /* 为下一个桶对应的input[]左端 */
        }
    }
}

vector<int> MSDRadixSort(const vector<int> input)
{ /* 统一接口 */
    vector<int>ret(input);int N=input.size();
    MSD(ret, 0, N-1, MaxDigit);
    return ret;
}
