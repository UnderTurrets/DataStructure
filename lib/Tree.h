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
    BinTree(){
        val;
        this->left=NULL;
        this->right=NULL;
    }
    BinTree( const BinTree<T> &that){
        val=(that.val);left=(that.left);right=(that.right);
    }
    bool operator< (BinTree<T> that){
        return this->val<that.val;
    }
    bool operator<= (BinTree<T> that){
        return this->val<=that.val;
    }
    bool operator> (BinTree<T> that){
        return this->val>that.val;
    }
    bool operator>= (BinTree<T> that){
        return this->val>=that.val;
    }
    bool operator== (BinTree<T> that){
        return this->val==that.val;
    }
    BinTree<T> operator= (BinTree<T> that){
        this->val=that.val;
        this->left=that.left;
        this->right=that.right;
        return *this;
    }

    //先序遍历非递归
    void Travesal_preorder_common(){
        stack<BinTree<T>*> S;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                if(temp->right)S.push(temp->right);
                if(temp->left)S.push(temp->left);
                S.push(temp);
                S.push(NULL);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
            }
        }
    }

    //中序遍历非递归
    void Travesal_inorder_common(){
        stack<BinTree<T>*> S;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                if(temp->right)S.push(temp->right);
                S.push(temp);
                S.push(NULL);
                if(temp->left)S.push(temp->left);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
            }
        }
    }

    //后序遍历非递归
    void Travesal_postorder_common(){
        stack<BinTree<T>*> S;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                S.push(temp);
                S.push(NULL);
                if(temp->right)S.push(temp->right);
                if(temp->left)S.push(temp->left);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
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

    //按层形成二维数组（层序遍历的应用）
    vector<vector<int>> levelOrder() {
        vector<vector<int>>ret;
        queue<BinTree<T>*> Q;
        if(!this)return {{}};
        Q.push(this);
        while (!Q.empty()){
            int x=Q.size();
            ret.push_back(vector<int>());
            for(int i=0;i<x;i++){
                auto node=Q.front();Q.pop();
                ret.back().push_back(node->val);
                if(node->left){Q.push(node->left);}
                if(node->right){Q.push(node->right);}
            }
        }
        return ret;
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

    //检验对称二叉树
public:
    inline bool IsSymmetric(){
        check(this, this);
    }
private:
    bool check(BinTree<T>root1,BinTree<T>root2){
        BinTree<T>* p= this;
        BinTree<T>* q= this;
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

public:
    //翻转二叉树
    BinTree<T>* InvertTree(BinTree<T> myself){
        if (myself == nullptr) {
            return nullptr;
        }
        BinTree<T>* left = invertTree(myself->left);
        BinTree<T>* right = invertTree(myself->right);
        myself->left = right;
        myself->right = left;
        return myself;

    }

    //给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
    bool hasPathSum(BinTree<T>* myself, int targetSum) {
        if(!myself)return false;
        if(!myself->left&&!myself->right)return targetSum==myself->val;
        return hasPathSum(myself->left,targetSum-myself->val) || hasPathSum(myself->right,targetSum-myself->val);
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

#endif