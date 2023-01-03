#ifndef __Tree_h__
#define __Tree_h__

#include "authority.h"

//树
template<class T>
class BinTree{
public:
    T val;
    BinTree<T> *left=NULL;
    BinTree<T> *right=NULL;
    BinTree();
    BinTree( const BinTree<T> &that);

    //重载运算符，基于val进行比较
    bool operator< (BinTree<T> that);
    bool operator<= (BinTree<T> that);
    bool operator> (BinTree<T> that);
    bool operator>= (BinTree<T> that);
    bool operator== (BinTree<T> that);
    BinTree<T> operator= (BinTree<T> that);

    //先序遍历非递归
    void Travesal_preorder_common();

    //中序遍历非递归
    void Travesal_inorder_common();

    //后序遍历非递归
    void Travesal_postorder_common();

    //层序遍历
    void Travesal_levelorder();

    //按层形成二维数组（层序遍历的应用）
    vector<vector<int>> levelOrder() ;

    //先序遍历递归，以所给参数为根节点开始遍历
    void Travesal_preorder_recurrence (BinTree<T> *myself);

    //中序遍历递归，以所给参数为根节点开始遍历
    void Travesal_inorder_recurrence (BinTree<T> *myself);

    //后序遍历递归，以所给参数为根节点开始遍历
    void Travesal_postorder_recurrence (BinTree<T> *myself);

    //得到树的高度，以所给参数为根节点开始计算高度
    int GetHeight (BinTree<T> *myself);

    //检验对称二叉树
public:
    inline bool IsSymmetric();
private:
    bool check(BinTree<T>root1,BinTree<T>root2);

public:
    //翻转二叉树
    BinTree<T>* InvertTree(BinTree<T> myself);

    //给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
    bool hasPathSum(BinTree<T>* myself, int targetSum) ;

    //给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
private:
    bool inline_IsValidBST(BinTree<T>* root, long long lower, long long upper) ;
public:
    bool IsValidBST() ;

public:
    //基于二叉搜索树的查找操作，返回值为所找到的元素的节点，若找不到则返回NULL，以所给参数为根节点开始查找
    BinTree<T>* Find_recurrence(T x,BinTree<T> *bt);
    BinTree<T>* Find_commone(T x,BinTree<T> * bt);

    //给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
    bool findTarget(BinTree<T>* root, int k) ;

    //给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    //百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    BinTree<T>* lowestCommonAncestor(BinTree<T>* p, BinTree<T>* q) ;

    //基于二叉搜索树找最大值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    BinTree<T>* FindMax_recurrence(BinTree<T>* bt);
    BinTree<T>* FindMax_common(BinTree<T>* bt);

    //基于二叉搜索树找最小值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    BinTree<T>* FindMin_recurrence(BinTree<T>* bt);
    BinTree<T>* FindMin_common(BinTree<T>* bt);

    //基于二叉搜索树插入某个元素，需要给定二叉搜索树的根结点和所插入元素，返回值也是二叉搜索树的根结点,若插入的元素已经存在，返回NULL
    BinTree<T>* insert(T x,BinTree<T>* myself);

    //基于二叉搜索树删除某个元素，需要给定二叉搜索树的根结点和所删除元素，返回值也是二叉搜索树的根结点
    BinTree<T>* delete_BinTree (T x,BinTree<T>* bt);
};

#endif