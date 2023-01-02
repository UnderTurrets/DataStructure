#include "Sort.h"


//冒泡排序
template<typename T>
vector<T> BubbleSort(vector<T> input){
    vector<T>output(input);
    for(int i=output.size()-1;i>=0;i++){
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
vector<T> InsertionSort(vector<T> input){
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
vector<T> ShellSort(vector<T>input){
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
vector<T> HeapSort(vector<T>input){
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
vector<T> MergeSortRecurrence( vector<T>A){ /* 归并排序 */
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
vector<T> MergeSortCommon( vector<T>A){
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