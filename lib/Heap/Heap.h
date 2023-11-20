#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "Tree.h"

//堆
//堆的定义，最大堆和最小堆是其子类
template<typename T>
class Heap {
public:
    mutable T *array=NULL;    //从下标1开始存储
    mutable int size=0;    //不包含this->array[0]
    mutable int capacity=0;    //不包含this->array[0]
    T LimitData;    //这是一个大于或小于堆中所有元素的极限元素，目的是为了以后更快地操作

    //重载运算符进行赋值构造
    inline Heap<T> operator= (const Heap<T>that);

    //构造函数
    inline ~Heap();
    inline Heap();

    //拷贝构造（深拷贝）
    inline Heap(const Heap<T> &H );

    //以某一容量创建一个堆
    inline Heap(const int Maxcapacity) ;

    //以一个完全二叉树创建一个堆，输入的树必须是 完全二叉树！！！
    inline Heap(const BinTree<T> bt);

    //以一个数组创建一个堆
    inline Heap(const vector<T> v);

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
    inline ~MaxHeap();
    //构造函数
    inline MaxHeap();

    //重载运算符进行赋值构造
    inline MaxHeap<T> operator= (const MaxHeap<T>that);

    //拷贝构造
    inline MaxHeap(const MaxHeap<T> &H);

    //以某一容量创建一个堆
    inline MaxHeap(const int Maxcapacity);

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    inline MaxHeap(const BinTree<T> bt);

    //以一个数组创建一个堆
    inline MaxHeap(const vector<T> v);

    //以其父类创建一个堆
    inline MaxHeap(const Heap<T> &H);

    //插入一个元素
    void insert(const T val) ;

    //删除顶部元素,返回值就是顶部元素
    T deleteMax();

    //将这个堆中this->array[i]为根的子堆整理成最大堆
    void PercDown(const int i);

    //将这个堆整理成最大堆
    void TidyUp();
};

//最小堆的定义
template<typename T>
class MinHeap:public Heap<T>{
public:
    ~MinHeap();
    //构造函数
    MinHeap();
     
    //重载运算符进行赋值构造
    inline MinHeap<T> operator= (const MinHeap<T>that);

    //拷贝构造
    inline MinHeap(const MinHeap<T> &H);

    //以某一容量创建一个堆
    inline MinHeap(const int Maxcapacity);

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    inline MinHeap(const BinTree<T> bt);

    //以一个数组创建一个堆
    inline MinHeap(const vector<T> v);

    //以其父类创建一个堆
    inline MinHeap(const Heap<T> &H);

    //插入一个元素
    void insert(const T val);

    //删除顶部元素,返回值就是顶部元素
    T deleteMin();

    //将这个堆中this->array[i]为根的子堆整理成最小堆
    void PercDown(const int i);

    //将这个堆整理成最小堆
    void TidyUp();

    //用最小堆构建一个哈夫曼树
    BinTree<T>* HuffMan ();
};


