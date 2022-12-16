#ifndef __myalgorithm_h__
#define  __myalgorithm_h__


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
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

//    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
vector<int> twoSum  (vector<int>& nums, int target);

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

//    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
int maxProfit(vector<int>& prices);

//    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//    给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
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
};

//得到树的高度
template<class T>
int GetHeight (BinTree<T> *bt){
    int heifht_left,height_right,height;
    if(bt){
        heifht_left=GetHeight(bt->left);
        height_right=GetHeight(bt->right);
        height= max(heifht_left,height_right);
        return (height+1);
    } else{
        return 0;
    }
}

//先序遍历递归
template<class T>
void Travesal_preorder_recurrence (BinTree<T> *bt){
    if(bt){
        //在此进行你要执行的操作
        cout<<bt->val<<endl;




        //在此以上进行你要执行的操作
        Travesal_preorder_recurrence(bt->left);
        Travesal_preorder_recurrence(bt->right);
    }
}

//中序遍历递归
template<class T>
void Travesal_inorder_recurrence (BinTree<T> bt){
    BinTree<T> *temp=bt;
    if(temp){
        Travesal_preorder_recurrence(temp->left);
        //在此进行你要执行的操作
        cout<<temp->val<<endl;





        //在此以上进行你要执行的操作
        Travesal_preorder_recurrence(temp->right);
    }
}
//后序遍历递归
template<class T>
void Travesal_postorder_recurrence (BinTree<T> bt){
    BinTree<T> *temp=bt;
    if(temp){
        Travesal_preorder_recurrence(temp->left);
        Travesal_preorder_recurrence(temp->right);
        //在此进行你要执行的操作



        //在此以上进行你要执行的操作
    }
}
#endif