#ifndef __Heap_h__
#define __Heap_h__

#include "authority.h"
#include "Tree.h"

//堆
//堆的定义，最大堆和最小堆是其子类
template<typename T>
class Heap {
public:
    T *array=NULL;//从下标1开始存储
    int size=0;
    int capacity=0;
    T LimitData;//这是一个大于或小于堆中所有元素的极限元素，目的是为了以后更快地操作

    Heap<T> operator= (Heap<T>that);

    Heap();

    //拷贝构造（深拷贝）
    Heap(Heap<T> &H );

    //以某一容量创建一个堆
    Heap(int Maxcapacity) ;

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    Heap(BinTree<T> bt);

    //以一个数组创建一个堆
    Heap(vector<T> v);

    //判断是否满员
    inline bool IsFull();

    //判断是否为空
    inline bool IsEmpty() ;

    //依次输出
    inline void print_heap();

};

//最大堆的定义
template<typename T>
class MaxHeap:public Heap<T>{
public:
    MaxHeap();

    MaxHeap<T> operator= (MaxHeap<T>that);

    //拷贝构造
    MaxHeap(MaxHeap<T> &H);

    //以某一容量创建一个堆
    MaxHeap(int Maxcapacity);

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    MaxHeap(BinTree<T> bt);

    //以一个数组创建一个堆
    MaxHeap(vector<T> v);

    //以其父类创建一个堆
    MaxHeap(Heap<T> &H);

    //插入一个元素
    void insert(T val) ;

    //删除顶部元素,返回值就是顶部元素
    T deleteMax();

    //将这个堆中this->array[i]为根的子堆整理成最大堆
    void PercDown(int i);

    //将这个堆整理成最大堆
    void TidyUp();
};

//最小堆的定义
template<typename T>
class MinHeap:public Heap<T>{
public:
    MinHeap();

    MinHeap<T> operator= (MinHeap<T>that);

    //拷贝构造
    MinHeap(MinHeap<T> &H);

    //以某一容量创建一个堆
    MinHeap(int Maxcapacity);

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    MinHeap(BinTree<T> bt);

    //以一个数组创建一个堆
    MinHeap(vector<T> v);

    //以其父类创建一个堆
    MinHeap(Heap<T> &H);

    //插入一个元素
    void insert(T val);

    //删除顶部元素,返回值就是顶部元素
    T deleteMin();

    //将这个堆中this->array[i]为根的子堆整理成最小堆
    void PercDown(int i);

    //将这个堆整理成最小堆
    void TidyUp();


};



#endif