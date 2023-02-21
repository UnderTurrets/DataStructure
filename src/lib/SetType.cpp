#include "SetType.h"
template<typename T>
bool SetTypeElement<T>::operator== (SetTypeElement<T>that){
    return this->val==that.val && this->parent==that.parent;
}


template<typename T>
SetType<T>::SetType(){
    this->totalNumber=100;
    this->collection.resize(this->totalNumber);
    this->Initialize();
}

template<typename T>
SetType<T>::SetType(int n){
    this->totalNumber=n;
    this->collection.resize(this->totalNumber);
    this->Initialize();
}

//初始化并查集
template<typename T>
void SetType<T>::Initialize(){
    for(int i=0;i<this->totalNumber;i++){
        this->collection[i].parent=-1;
    }
}

//给出元素得到其在集合中的下标,不存在则返回-1
template<typename T>
int SetType<T>::GetIndex(const T val){
    for(int i=0;i<this->totalNumber;i++){
        if(this->collection[i].val==val){
            return i;
        }
    }
    return -1;
}

//把集合合并,必须给出两个根节点的下标
template<typename T>
void SetType<T>::Union(const int Root1_index,const int Root2_index) {
    /* 保证小集合并入大集合 */
    if ( this->collection[Root2_index].parent < this->collection[Root1_index].parent ) { /* 如果集合2比较大 */
        this->collection[Root2_index].parent += this->collection[Root1_index].parent;     /* 集合1并入集合2  */
        this->collection[Root1_index].parent = Root2_index;
    }
    else {                         /* 如果集合1比较大 */
        this->collection[Root1_index].parent += this->collection[Root2_index].parent;     /* 集合2并入集合1  */
        this->collection[Root2_index].parent = Root1_index;
    }
}

//给出一个元素的下标，找到此元素的根
template<typename T>
int SetType<T>::Find(const int index){
    if(this->collection[index].parent<0){
        return index;
    }else{
        return this->collection[index].parent=Find(this->collection[index].parent);//路径压缩
    }
}

//给出两个元素的下标，检查两个元素是否属于同一集合
template<typename T>
bool SetType<T>::Check(const int index1,const int index2){
    int Root1 =this->Find(index1);
    int Root2 =this->Find(index2);
    if(Root1==Root2){
        return true;
    }else{
        return false;
    }
}

template<typename T>
SetType<T>::~SetType() {
    delete this;
}
