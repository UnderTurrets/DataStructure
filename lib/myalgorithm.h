#ifndef __myalgorithm_h__
#define  __myalgorithm_h__


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <functional>
#include <exception>

using namespace std;
using namespace placeholders;

//判断一个数组中是否有相同元素
bool containsDuplicate(vector<int>& nums);

//寻找一个数组的最大子数组和
int maxSubArray(vector<int>& nums);

//    给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
//    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
vector<int> twoSum  (vector<int>& nums, int target);

//给你两个按 非递减顺序 排列的整数数组nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

//    给定一个数组 prices ，它的第i 个元素prices[i] 表示一支给定股票第 i 天的价格。
//    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
int maxProfit(vector<int>& prices);

//    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//    给你一个由二维数组 mat 表示的m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
//    重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
//    如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
vector<vector<int>> generate(int numRows);

//请你判断一个9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//数字1-9在每一行只能出现一次。
//数字1-9在每一列只能出现一次。
//数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。（请参考示例图）
bool find_repeat(vector<char> v);
bool isValidSudoku(vector<vector<char>>& board);

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
void setZeroes(vector<vector<int>>& matrix);

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
int firstUniqChar(string s);

//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
bool canConstruct(string ransomNote, string magazine);

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。
bool isAnagram(string s, string t);

//给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
bool isValid(string s);

//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环，则返回 true 。 否则，返回 false 。
// Definition for singly-linked list.
  struct ListNode;
bool hasCycle(ListNode *head);

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
ListNode* removeElements(ListNode* head, int val);












//树
template<class T>
class BinTree{
public:
    T val;
    BinTree<T> *left=NULL;
    BinTree<T> *right=NULL;
    BinTree<T>(){}
    BinTree<T>( const BinTree<T> &that){
        val=(that.val);left=(that.left);right=(that.right);
    }

    //中序遍历非递归
    void Travsal_inorder_common(){
        BinTree<T> *temp;
        temp= this;
        stack<BinTree<T>> S;
        while (temp||  !S.empty()){
            while (temp){
                S.push(*temp);
                temp=temp->left;
            }
            if(!S.empty()){
                temp=&S.top();S.pop();
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
                temp=temp->right;
            }
        }
    }


    //先序遍历非递归
    void Travsal_preorder_common(){
        BinTree<T> *temp;
        temp= this;
        stack<BinTree<T>> S;
        while (temp||  !S.empty()){
            while (temp){
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
                S.push(*temp);
                temp=temp->left;
            }
            if(!S.empty()){
                temp=&S.top();S.pop();
                temp=temp->right;
            }
        }
    }

    //层序遍历
    void Travesal_levelorder(){
        BinTree<T> *temp;
        temp=this;
        queue<BinTree<T>> Q;
        if(!temp)return;
        Q.push(*temp);
        while (!Q.empty()){
            temp=&Q.front();
            Q.pop();
            //在此进行你要执行的操作

           cout<<temp->val<<endl;

            //在此以上进行你要执行的操作
            if(temp->left){Q.push(*(temp->left));}
            if(temp->right){Q.push(*(temp->right));}
        }
    }

    //先序遍历递归，以所给参数为根节点开始遍历
    void Travesal_preorder_recurrence (BinTree<T> *myself){
        if(myself){
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_preorder_recurrence(myself->left);
            Travesal_preorder_recurrence(myself->right);
        }
    }

    //中序遍历递归，以所给参数为根节点开始遍历
    void Travesal_inorder_recurrence (BinTree<T> *myself){
        if(myself){
            Travesal_preorder_recurrence(myself->left);
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_preorder_recurrence(myself->right);
        }
    }
    //后序遍历递归，以所给参数为根节点开始遍历
    void Travesal_postorder_recurrence (BinTree<T> *myself){
        if(myself){
            Travesal_preorder_recurrence(myself->left);
            Travesal_preorder_recurrence(myself->right);
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
        }
    }

    //得到树的高度，以所给参数为根节点开始计算高度
    int GetHeight (BinTree<T> *myself){
        int heifht_left,height_right,height;
        if(myself){
            heifht_left=GetHeight(myself->left);
            height_right=GetHeight(myself->right);
            height= max(heifht_left,height_right);
            return (height+1);
        } else{
            return 0;
        }
    }

    //基于二叉搜索树的查找操作，返回值为所找到的元素的节点，若找不到则返回NULL，以所给参数为根节点开始查找
    BinTree<T>* Find_recurrence(T val,BinTree<T> *bt){
        if(!bt)return NULL;
        if(val>bt->val){
            return Find_recurrence(val,bt->right);
        } else if(val<bt->val){
            return Find_recurrence(val,bt->left);
        }else{
            return bt;
        }
    }
    BinTree<T>* Find_commone(T val,BinTree<T> * bt){
        if(!bt)return NULL;
        while (bt){
            if(val<bt->val){
                bt=bt->left;
            }else if(val>bt->val){
                bt=bt->right;
            }else{
                return bt;
            }
        }
    }

    //基于二叉搜索树找最大值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    BinTree<T>* FindMax_recurrence(BinTree<T>* bt){
        if(!bt)return NULL;
        else if(!bt->right)return bt;
        else if(bt->right)return FindMax_recurrence(bt->right);
    }
    BinTree<T>* FindMax_common(BinTree<T>* bt){
        if(bt){
            while (bt->right)bt=bt->right;
            return bt;
        }
        else if(bt==NULL){
            return  NULL;
        }
    }

    //基于二叉搜索树找最小值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    BinTree<T>* FindMin_recurrence(BinTree<T>* bt){
        if(!bt)return NULL;
        else if(!bt->left)return bt;
        else if(bt->left)return FindMin_recurrence(bt->left);
    }
    BinTree<T>* FindMin_common(BinTree<T>* bt){
        if(bt){
            while (bt->left)bt=bt->left;
            return bt;
        }
        else if(bt==NULL){
            return  NULL;
        }
    }

    //基于二叉搜索树插入某个元素，需要给定二叉搜索树的根结点和所插入元素，返回值也是二叉搜索树的根结点,若插入的元素已经存在，返回NULL
    BinTree<T>* insert(T val,BinTree<T>* bt){
        if(!bt){
            bt =new BinTree<T>;
            bt->val=val;
        } else{
            if(val<bt->val){
                bt->left= insert(val,bt->left);
            } else if(val>bt->val){
                bt->right= insert(val,bt->right);
            } else if(val==bt->val){
                return NULL;
            }
        }
        return bt;
    }

    //基于二叉搜索树删除某个元素，需要给定二叉搜索树的根结点和所删除元素，返回值也是二叉搜索树的根结点
    BinTree<T>* delete_BinTree (T val,BinTree<T>* bt){
        if(!bt)cout<<"The element you want to delete doesn't exist!"<<endl;
        else if(val<bt->val){
            bt->left= delete_BinTree(val,bt->left);
        }else if(val>bt->val){
            bt->right= delete_BinTree(val,bt->right);
        }else if(val==bt->val){
            if(bt->left&&bt->right){
                BinTree<T> *temp= FindMin_common(bt->right);
                bt->val=temp->val;
                bt->right= delete_BinTree(bt->val,bt->right);
            }else{
                if(!bt->left)bt=bt->right;
                else if(!bt->right)bt=bt->left;
            }
        }
        return bt;
    }

};

//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
ListNode* deleteDuplicates(ListNode* head);

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
ListNode* reverseList(ListNode* head);

//栈
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//T pop() 从队列的开头移除并返回元素
//T peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//你 只能 使用标准的栈操作 —— 也就是只有push to top,peek/pop from top,size, 和is empty操作是合法的。
template<class T>
class MyQueue {
public:
    stack<T>instack;
    stack<T>outstack;
    MyQueue<T>() {}
    void push(T x) {
        instack.push(x);
    }

    T pop() {
        T ret;
        if(outstack.empty()){
            while (!instack.empty()){
                T temp=instack.top();instack.pop();
                outstack.push(temp);
            }
        }
        ret=outstack.top();
        outstack.pop();
        return ret;
    }

    T peek() {
        T ret;
        if(outstack.empty()){
            while (!instack.empty()){
                T temp=instack.top();instack.pop();
                outstack.push(temp);
            }
        }
        ret=outstack.top();
        return ret;
    }

    bool empty() {
        return instack.empty()&&outstack.empty();
    }
};

//堆
//最大堆的定义，最小堆可仿照此定义
template<typename T>
class MaxHeap{
public:
    T *array;//从下标1开始存储
    int size;
    int capacity;
    T LimitData;//这是一个大于或小于堆中所有元素的极限元素，目的是为了以后更快地操作

    //不给出大小是不能定义堆的
//    heap(){
//        this->array=new T(size+1);
//        array[0]=LimitData;
//    }

    //创建一个堆
    MaxHeap(int Maxsize){
        this->array=new T(Maxsize+1);
        this->size=0;
        this->capacity=Maxsize;
        this->array[0]=LimitData;
    }

    //判断是否满员
    bool IsFull(){
        return (this->Size == this->Capacity);
    }

    //判断是否为空
    bool IsEmpty(){
        return (this->Size == 0);
    }

    //插入一个元素
    void insert(T val){
        int i;
        if(this->IsFull()){
            cout<<"This heap is full and your operation has failed!"<<endl;
            return;
        }
        this->size++;
        i= this->size;
        for(;this->array[i/2]<val && i>1;i/=2){
            this->array[i]= this->array[i/2];
        }
        this->array[i]=val;
    }

    //删除顶部元素,返回值就是顶部元素
    T deleteMax(){
        int parent,child;
        T temp= this->array[this->size];T max=this->array[1];
        this->size--;
        if(this->IsEmpty()){
            cout<<"The heap is empty and your operation has failed!"<<endl;
            return;
        }
        for(parent=1;parent*2<= this->size;parent=child){
            child=parent*2;
            if(child!= this->size && this->array[child]< this->array[child+1]){
                child++;
            }
            if(temp>= this->array[child]){
                break;
            }else{
                this->array[parent]=this->array[child];
            }
        }
        this->array[parent]=temp;
        return max;
    }

    //将这个堆整理成最大堆
    void TidyUp(){
        for(int i= this->size/2;i>0;i--){
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
    }
};

//最小堆的定义
template<typename T>
class MinHeap{
public:
    T *array;//从下标1开始存储
    int size;
    int capacity;
    T LimitData;//这是一个大于或小于堆中所有元素的极限元素，目的是为了以后更快地操作

    //不给出大小是不能定义堆的
//    heap(){
//        this->array=new T(size+1);
//        array[0]=LimitData;
//    }

    //创建一个堆
    MinHeap(int Maxsize){
        this->array=new T(Maxsize+1);
        this->size=0;
        this->capacity=Maxsize;
        this->array[0]=LimitData;
    }

    //判断是否满员
    bool IsFull(){
        return (this->Size == this->Capacity);
    }

    //判断是否为空
    bool IsEmpty(){
        return (this->Size == 0);
    }

    //插入一个元素
    void insert(T val){
        int i;
        if(this->IsFull()){
            cout<<"This heap is full and your operation has failed!"<<endl;
            return;
        }
        this->size++;
        i= this->size;
        for(;this->array[i/2]>val && i>1;i/=2){
            this->array[i]= this->array[i/2];
        }
        this->array[i]=val;
    }

    //删除顶部元素,返回值就是顶部元素
    T deleteMax(){
        int parent,child;
        T temp= this->array[this->size];T min=this->array[1];
        this->size--;
        if(this->IsEmpty()){
            cout<<"The heap is empty and your operation has failed!"<<endl;
            return;
        }
        for(parent=1;parent*2<= this->size;parent=child){
            child=parent*2;
            if(child!= this->size && this->array[child]> this->array[child+1]){
                child++;
            }
            if(temp<= this->array[child]){
                break;
            }else{
                this->array[parent]=this->array[child];
            }
        }
        this->array[parent]=temp;
        return max;
    }

    //将这个堆整理成最小堆
    void TidyUp(){
        for(int i= this->size/2;i>0;i--){
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
    }
};






#endif