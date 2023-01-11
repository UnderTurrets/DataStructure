#ifndef __Tree_h__
#define __Tree_h__

#include "authority.h"

//树
template<typename T>
class BinTree{
public:
    T val;
    BinTree<T> *left=nullptr;
    BinTree<T> *right=nullptr;
    BinTree();
    BinTree( T x);
    BinTree( const BinTree<T> &that);

    //给你一个整数数组 nums ，请你将其转换为一棵 高度平衡 二叉搜索树。
    //高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
public:
    BinTree(vector<T> nums);
private:
    BinTree<T>* sortedArrayToBST_helper(vector<T>nums, int left, int right);
    
public:
    //给定两个整数数组preorder 和 inorder，其中preorder 是二叉树的先序遍历， inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。
    //1 <= preorder.length <= 3000
    //inorder.length == preorder.length
    //-3000 <= preorder[i], inorder[i] <= 3000
    //preorder和inorder均 无重复 元素
    //inorder均出现在preorder
    //preorder保证 为二叉树的前序遍历序列
    //inorder保证 为二叉树的中序遍历序列
    BinTree(vector<T> preorder, vector<T> inorder);

    //重载运算符，基于val进行比较
    bool operator< (BinTree<T> that);
    bool operator<= (BinTree<T> that);
    bool operator> (BinTree<T> that);
    bool operator>= (BinTree<T> that);
    bool operator== (BinTree<T> that);
    BinTree<T> operator= (BinTree<T> that);

    //先序遍历非递归
    void Travesal_preorder_common();

    //按先序顺序把二叉树转为数组
    vector<T> preorder_BT2VECTOR();

    //中序遍历非递归
    void Travesal_inorder_common();

    //按中序顺序把二叉树转为数组
    vector<T> inorder_BT2VECTOR();

    //后序遍历非递归
    void Travesal_postorder_common();

    //按后序顺序把二叉树转为数组
    vector<T> postorder_BT2VECTOR();

    //层序遍历
    void Travesal_levelorder();

    //按层形成二维数组（层序遍历的应用）
    vector<vector<T>> levelOrder() ;

    //给你二叉树的根节点 this ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
    vector<vector<T>> zigzagLevelOrder();

    //先序遍历递归，以所给参数为根节点开始遍历
private:
    void Travesal_preorder_recurrence_helper (BinTree<T> *root);
public:
    void Travesal_preorder_recurrence ();

    //中序遍历递归，以所给参数为根节点开始遍历
private:
    void Travesal_inorder_recurrence_helper (BinTree<T> *root);
public:
    void Travesal_inorder_recurrence ();

    //后序遍历递归，以所给参数为根节点开始遍历
private:
    void Travesal_postorder_recurrence_helper (BinTree<T> *root);
public:
    void Travesal_postorder_recurrence ();

    //给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
    vector<T> rightSideView();

    //得到树的高度，以所给参数为根节点开始计算高度
private:
    int GetHeight_helper (BinTree<T> *root);
public:
    int GetHeight();

    //检验对称二叉树
public:
    inline bool IsSymmetric();
private:
    bool IsSymmetric_helper(BinTree<T>root1,BinTree<T>root2);

    //翻转二叉树
private:
    BinTree<T>* InvertTree_helper(BinTree<T>* root);
public:
    void InvertTree();

    //给你二叉树的根节点this 和一个表示目标和的数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
private:
    bool hasPathSum_helper(BinTree<T>* root, T targetSum);
public:
    bool hasPathSum(T targetSum);

    //给你二叉树的根节点 this 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
private:
    void pathSum_helper(BinTree<T>*root,T targetSum,vector<vector<T>>&ret,vector<T>&path);
public:
    vector<vector<T>> pathSum(T targetSum);

    //给你一个二叉树的根节点 this ，判断其是否是一个有效的二叉搜索树。
private:
    bool IsValidBST_helper(BinTree<T>* root, long long lower, long long upper) ;
public:
    bool IsValidBST() ;

    //基于二叉搜索树的查找操作，返回值为所找到的元素的节点，若找不到则返回nullptr，以所给参数为根节点开始查找
private:
    BinTree<T>* Find_recurrence_helper(T x,BinTree<T> *root);
public:
    BinTree<T>* Find_recurrence(T x);
public:
    BinTree<T>* Find_common(T x);

    //给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
    T kthSmallest(int k);

    //给定一个二叉搜索树 this 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
    bool findTarget(T k) ;

    //给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    //百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    BinTree<T>* lowestCommonAncestorBST(T p, T q) ;
    BinTree<T>* lowestCommonAncestorBST(BinTree<T>* p, BinTree<T>* q) ;

    //给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    //百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
private:
    BinTree<T>* lowestCommonAncestor_helper(BinTree<T>* root, T p, T q);
public:
    BinTree<T>* lowestCommonAncestor( T p, T q);
    BinTree<T>* lowestCommonAncestor( BinTree<T>* p, BinTree<T>* q);

    //基于二叉搜索树找最大值，返回其最大值的结点,以所给参数为根结点进行查找
private:
    BinTree<T>* FindMax_recurrence_helper(BinTree<T>* root);
public:
    BinTree<T>* FindMax_recurrence();
    BinTree<T>* FindMax_common();

    //基于二叉搜索树找最小值，返回其最小值的结点，以所给参数为根结点进行查找
private:
    BinTree<T>* FindMin_recurrence_helper(BinTree<T>* root);
public:
    BinTree<T>* FindMin_recurrence();
    BinTree<T>* FindMin_common();

    //基于二叉搜索树插入某个元素，需要给定所插入元素，返回值是插入后二叉搜索树的根结点,若插入的元素已经存在，返回nullptr
private:
    BinTree<T>* insert_helper(T x,BinTree<T>* root);
public:
    BinTree<T>* insert(T x);

    //基于二叉搜索树删除某个元素，需要给定所删除元素，返回值是删除后二叉搜索树的根结点,若删除的元素不存在，返回nullptr
private:
    BinTree<T>* delete_bt_helper (T x,BinTree<T>* root);
public:
    BinTree<T>* delete_bt(T x);

    //序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
    //请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
    // Encodes a tree to a single string.
    string serialize2String();




};
//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
//请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
// Decodes your encoded data to tree.
template<typename T>
BinTree<T>* deserialize2BT(string data);









//树的中序迭代器
template<typename T>
class InOrderBtIter {
public:
    BinTree<T>* target;
    stack<BinTree<T>*> S;

    //重载运算符
    InOrderBtIter<T> operator= (InOrderBtIter<T> that);
    InOrderBtIter<T> operator++ ();
    T operator* ();

    InOrderBtIter();
    InOrderBtIter(BinTree<T>* root);

    T next();

    bool hasNext();
};

#endif