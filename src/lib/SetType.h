#ifndef __SetType_h__
#define __SetType_h__
#include "authority.h"
//集合中的单个元素的定义
template<typename T>
class SetTypeElement{
public:
    T val;
    int parent=-1;
    inline bool operator== (SetTypeElement<T>that);
};


template<typename T>
class SetType{
public:
    vector<SetTypeElement<T>>collection;
    int totalNumber;
    SetType();
    SetType(int n);

    //初始化并查集
    void Initialize();

    //给出元素得到其在集合中的下标
    int GetIndex(const T set);

    //把集合合并,必须给出两个根节点
    void Union(const int Root1_index,const int Root2_index);

    //给出一个元素的下标，找到此元素的根
    inline int Find(const int index);

//给出两个元素的下标，检查两个元素是否属于同一集合
    bool Check(const int index1,const int index2);

};
#endif
