#include "Heap.h"


//堆

    template<typename T>
    Heap<T> Heap<T>::operator= (Heap<T>that){
        if(this->array)delete[] this->array;
        this->size=that.size;
        this->capacity=that.capacity;
        this->LimitData=that.LimitData;
        this->array=new T[that.capacity+1];
        for(int i=1;i<=this->size;i++){
            this->array[i]=that.array[i];
        }
    }

    template<typename T>
    Heap<T>::Heap(){
        if(this->array)delete[] this->array;
        this->size=0;
        this->capacity=0;
        this->array=new T[this->capacity+1];
        this->array[0]=this->LimitData;
    }

    //拷贝构造（深拷贝）
    template<typename T>
    Heap<T>::Heap(Heap<T> &H ){
        if(this->array)delete[] this->array;
        this->array=new T[H.capacity+1];
        this->size=H.size;
        this->capacity=H.capacity;
        this->LimitData=H.LimitData;
        for(int i=1;i<=H.size;i++){
            this->array[i]=H.array[i];
        }
    }

    //以某一容量创建一个堆
    template<typename T>
    Heap<T>::Heap(int Maxcapacity) {
        if(this->array)delete[] this->array;
        this->array = new T[Maxcapacity + 1];
        this->size = 0;
        this->capacity = Maxcapacity;
        this->array[0] = this->LimitData;
    }

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    template<typename T>
    Heap<T>::Heap(BinTree<T> bt){
        if(this->array)delete[] this->array;
        int x=pow(2,bt.GetHeight(&bt)+1);
        this->array=new T[x+1];
        this->capacity=pow(2,bt.GetHeight(&bt)+1);
        this->size=0;T max=bt.val;
        BinTree<T> *temp;
        temp=&bt;int i =1;
        queue<BinTree<T>> Q;
        if(!temp)return;
        Q.push(*temp);
        while (!Q.empty()){
            temp=&Q.front();
            Q.pop();
            //在此进行你要执行的操作
            this->size++;
            this->array[i]=temp->val;
            i++;
            //在此以上进行你要执行的操作
            if(temp->left){Q.push(*(temp->left));}
            if(temp->right){Q.push(*(temp->right));}
        }
    }

    //以一个数组创建一个堆
    template<typename T>
    Heap<T>::Heap(vector<T> v){
        if(this->array)delete[] this->array;
        this->array=new T[v.capacity()+1];
        this->size=v.size();
        this->capacity=v.capacity();
        for(int i=0;i<v.size();i++){
            this->array[i+1]=v[i];
        }
    }

    //判断是否满员
    template<typename T>
    inline bool Heap<T>::IsFull() {
        return (this->size == this->capacity);
    }

    //判断是否为空
    template<typename T>
    inline bool Heap<T>::IsEmpty() {
        return (this->size == 0);
    }

    //依次输出
    template<typename T>
    inline void Heap<T>::print_heap(){
        for(int i=1;i<=(this->size);i++){
            cout<<this->array[i]<<' ';
        }
        cout<<endl;
    }



//最大堆

    template<typename T>
    MaxHeap<T>::MaxHeap(){
        if(this->array)delete[] this->array;
        this->size=0;
        this->capacity=0;
        this->array=new T[this->capacity+1];
        this->array[0]=this->LimitData;
    }

    template<typename T>
    MaxHeap<T> MaxHeap<T>::operator= (MaxHeap<T>that){
        if(this->array)delete[] this->array;
        this->size=that.size;
        this->capacity=that.capacity;
        this->LimitData=that.LimitData;
        this->array=new T[that.capacity+1];
        for(int i=1;i<=this->size;i++){
            this->array[i]=that.array[i];
        }
    }

    //拷贝构造
    template<typename T>
    MaxHeap<T>::MaxHeap(MaxHeap<T> &H):Heap<T>(H){}

    //以某一容量创建一个堆
    template<typename T>
    MaxHeap<T>::MaxHeap(int Maxcapacity): Heap<T>(Maxcapacity){}

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    template<typename T>
    MaxHeap<T>::MaxHeap(BinTree<T> bt): Heap<T>(bt){
        this->TidyUp();
    }

    //以一个数组创建一个堆
    template<typename T>
    MaxHeap<T>::MaxHeap(vector<T> v): Heap<T>(v){
        this->TidyUp();
    }

    //以其父类创建一个堆
    template<typename T>
    MaxHeap<T>::MaxHeap(Heap<T> &H): Heap<T>(H){
        this->TidyUp();
    }

    //插入一个元素
    template<typename T>
    void MaxHeap<T>::insert(T val) {
        if (this->IsFull()) {
            T *temp=this->array;
            this->array=NULL;
            this->array=new T[(this->capacity)*2];
            this->capacity++;
            for(int i=1;i<=this->size;i++){
                this->array[i]=temp[i];
            }
        }
        this->size++;
        int i= this->size;
        for (; this->array[i / 2] < val && i > 1; i /= 2) {
            this->array[i] = this->array[i / 2];
        }
        this->array[i] = val;
    }

    //删除顶部元素,返回值就是顶部元素
    template<typename T>
    T* MaxHeap<T>::deleteMax(){
        if(this->size>0) {
            int parent, child;
            T temp = this->array[this->size];
            T *max = this->array[1];
            if (this->IsEmpty()) {
                cout << "The heap is empty and your operation has failed!" << endl;
                return this->array[0];
            }
            this->size--;
            for (parent = 1; parent * 2 <= this->size; parent = child) {
                child = parent * 2;
                if (child != this->size && this->array[child] < this->array[child + 1]) {
                    child++;
                }
                if (temp >= this->array[child]) {
                    break;
                } else {
                    this->array[parent] = this->array[child];
                }
            }
            this->array[parent] = temp;
            return max;
        }else{
            return NULL;
        }
    }

    //将这个堆中this->array[i]为根的子堆整理成最大堆
    template<typename T>
    void MaxHeap<T>::PercDown(int i){
        int parent,child;
        T x;
        x= this->array[i];
        for(parent=i;parent*2 <= this->size;parent=child){
            child=parent*2;
            if(child!= this->size && this->array[child]< this->array[child+1]){
                child++;
            }
            if(x >= this->array[child]){
                break;
            } else{
                this->array[parent]= this->array[child];
            }
        }
        this->array[parent]=x;
    }

    //将这个堆整理成最大堆
    template<typename T>
    void MaxHeap<T>::TidyUp(){
        for(int i= this->size/2;i>0;i--){
            this->PercDown(i);
        }
    }


//最小堆

    template<typename T>
    MinHeap<T>::MinHeap(): Heap<T>(){}

    template<typename T>
    MinHeap<T> MinHeap<T>::operator= (MinHeap<T>that){
        if(this->array)delete[] this->array;
        this->size=that.size;
        this->capacity=that.capacity;
        this->LimitData=that.LimitData;
        this->array=new T[that.capacity+1];
        for(int i=1;i<=this->size;i++){
            this->array[i]=that.array[i];
        }
    }

    //拷贝构造
    template<typename T>
    MinHeap<T>::MinHeap(MinHeap<T> &H): Heap<T>(H){}

    //以某一容量创建一个堆
    template<typename T>
    MinHeap<T>::MinHeap(int Maxcapacity): Heap<T>(Maxcapacity){}

    //以一个完全二叉树创建一个堆，记住：输入的树必须是 完全二叉树！！！
    template<typename T>
    MinHeap<T>::MinHeap(BinTree<T> bt): Heap<T>(bt){
        this->TidyUp();
    }

    //以一个数组创建一个堆
    template<typename T>
    MinHeap<T>::MinHeap(vector<T> v): Heap<T>(v){
        this->TidyUp();
    }

    //以其父类创建一个堆
    template<typename T>
    MinHeap<T>::MinHeap(Heap<T> &H): Heap<T>(H){
        this->TidyUp();
    }

    //插入一个元素
    template<typename T>
    void MinHeap<T>::insert(T val){
        if (this->IsFull()) {
            T *temp=this->array;
            this->array=NULL;
            this->array=new T[(this->capacity)*2];
            this->capacity++;
            for(int i=1;i<=this->size;i++){
                this->array[i]=temp[i];
            }
        }
        this->size+=1;
        int i= this->size;
        for(;this->array[i/2]>val && i>1;i/=2){
            this->array[i]= this->array[i/2];
        }
        this->array[i]=val;
    }

    //删除顶部元素,返回值就是顶部元素
    template<typename T>
    T* MinHeap<T>::deleteMin(){
        if(this->size>0 ) {
            int parent, child;
            T temp = this->array[this->size];
            T* min = this->array[1];
            if (this->IsEmpty()) {
                cout << "The heap is empty and your operation has failed!" << endl;
                return this->array[0];
            }
            this->size--;
            for (parent = 1; parent * 2 <= this->size; parent = child) {
                child = parent * 2;
                if (child != this->size && this->array[child] > this->array[child + 1]) {
                    child++;
                }
                if (temp <= this->array[child]) {
                    break;
                } else {
                    this->array[parent] = this->array[child];
                }
            }
            this->array[parent] = temp;
            return min;
        } else{
            return NULL;
        }
    }

    //将这个堆中this->array[i]为根的子堆整理成最大堆
    template<typename T>
    void MinHeap<T>::PercDown(int i){
        int parent,child;
        T x;
        x= this->array[i];
        for(parent=i;parent*2 <= this->size;parent=child){
            child=parent*2;
            if(child!= this->size && this->array[child]> this->array[child+1]){
                child++;
            }
            if(x <= this->array[child]){
                break;
            } else{
                this->array[parent]= this->array[child];
            }
        }
        this->array[parent]=x;
    }

    //将这个堆整理成最小堆
    template<typename T>
    void MinHeap<T>::TidyUp(){
        for(int i= this->size/2;i>0;i--){
            this->PercDown(i);
        }
    }




//用最小堆构建一个哈夫曼树
template<typename T>
BinTree<T> HuffMan (MinHeap<BinTree<T>> *minHeap){
    int i;BinTree<T>* temp;
    minHeap->TidyUp();
    for(i=1;i< minHeap->size;i++){
        temp=new BinTree<T>;
        BinTree<T>*x1=minHeap->deleteMin();
        BinTree<T>*x2=minHeap->deleteMin();
        temp->left = x1;
        temp->right= x2;
        temp->val=x1->val+x2->val;
        minHeap->insert(*temp);
    }
    BinTree<T>x=minHeap->deleteMin();
    temp=x;
    return *temp;
}


