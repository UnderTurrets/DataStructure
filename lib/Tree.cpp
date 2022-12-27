#include "Tree.h"

//树
template<typename T>
BinTree<T>::BinTree(){
    val;
    this->left=NULL;
    this->right=NULL;
}

template<typename T>
BinTree<T>::BinTree( const BinTree<T> &that){
        val=(that.val);left=(that.left);right=(that.right);
}

template<typename T>
bool BinTree<T>::operator< (BinTree<T> that){
        return this->val<that.val;
}

template<typename T>
bool BinTree<T>::operator<= (BinTree<T> that){
        return this->val<=that.val;
    }

template<typename T>
bool BinTree<T>::operator> (BinTree<T> that){
        return this->val>that.val;
    }

template<typename T>
bool BinTree<T>::operator>= (BinTree<T> that){
        return this->val>=that.val;
    }

template<typename T>
bool BinTree<T>::operator== (BinTree<T> that){
        return this->val==that.val;
    }

template<typename T>
    BinTree<T> BinTree<T>::operator= (BinTree<T> that){
        this->val=that.val;
        this->left=that.left;
        this->right=that.right;
        return *this;
    }

    //先序遍历非递归
    template<typename T>
    void BinTree<T>::Travesal_preorder_common(){
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
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
            }else{
                S.pop();
                temp=S.top();
                S.pop();
            }
        }
    }

    //中序遍历非递归
    template<typename T>
    void BinTree<T>::Travesal_inorder_common(){
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
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
            }else{
                S.pop();
                temp=S.top();
                S.pop();
            }
        }
    }

    //后序遍历非递归
    template<typename T>
    void BinTree<T>::Travesal_postorder_common(){
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
                //在此进行你要执行的操作
                cout<<temp->val<<endl;



                //在此以上进行你要执行的操作
            }else{
                S.pop();
                temp=S.top();
                S.pop();
            }
        }
    }

    //层序遍历
    template<typename T>
    void BinTree<T>::Travesal_levelorder(){
        BinTree<T> *temp;
        temp=this;
        queue<BinTree<T>*> Q;
        if(!temp)return;
        Q.push(temp);
        while (!Q.empty()){
            temp=Q.front();
            Q.pop();
            //在此进行你要执行的操作

            cout<<temp->val<<endl;

            //在此以上进行你要执行的操作
            if(temp->left){Q.push(temp->left);}
            if(temp->right){Q.push(temp->right);}
        }
    }

    //按层形成二维数组（层序遍历的应用）
    template<typename T>
    vector<vector<int>> BinTree<T>::levelOrder() {
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
    template<typename T>
    void BinTree<T>::Travesal_preorder_recurrence (BinTree<T> *myself){
        if(myself){
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_preorder_recurrence(myself->left);
            Travesal_preorder_recurrence(myself->right);
        }
    }

    //中序遍历递归，以所给参数为根节点开始遍历
    template<typename T>
    void BinTree<T>::Travesal_inorder_recurrence (BinTree<T> *myself){
        if(myself){
            Travesal_preorder_recurrence(myself->left);
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_preorder_recurrence(myself->right);
        }
    }

    //后序遍历递归，以所给参数为根节点开始遍历
    template<typename T>
    void BinTree<T>::Travesal_postorder_recurrence (BinTree<T> *myself){
        if(myself){
            Travesal_preorder_recurrence(myself->left);
            Travesal_preorder_recurrence(myself->right);
            //在此进行你要执行的操作
            cout<<myself->val<<endl;




            //在此以上进行你要执行的操作
        }
    }

    //得到树的高度，以所给参数为根节点开始计算高度
    template<typename T>
    int BinTree<T>::GetHeight (BinTree<T> *myself){
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
    template<typename T>
    inline bool BinTree<T>::IsSymmetric(){
        return check(this, this);
    }
    template<typename T>
    bool BinTree<T>::check(BinTree<T>root1,BinTree<T>root2){
        BinTree<T>* p= this;
        BinTree<T>* q= this;
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }


    //翻转二叉树
    template<typename T>
    BinTree<T>* BinTree<T>::InvertTree(BinTree<T> myself){
        if (myself == nullptr) {
            return nullptr;
        }
        BinTree<T>* bt1 = invertTree(myself->left);
        BinTree<T>* bt2 = invertTree(myself->right);
        myself->left = bt2;
        myself->right = bt1;
        return myself;

    }

    //给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
    template<typename T>
    bool BinTree<T>::hasPathSum(BinTree<T>* myself, int targetSum) {
        if(!myself)return false;
        if(!myself->left&&!myself->right)return targetSum==myself->val;
        return hasPathSum(myself->left,targetSum-myself->val) || hasPathSum(myself->right,targetSum-myself->val);
    }

    //给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
    template<typename T>
    bool BinTree<T>::inline_IsValidBST(BinTree<T>* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return inline_IsValidBST(root -> left, lower, root -> val) && inline_IsValidBST(root -> right, root -> val, upper);
    }
    template<typename T>
    bool BinTree<T>::IsValidBST() {
        return inline_IsValidBST(this, LONG_MIN, LONG_MAX);
    }

    //基于二叉搜索树的查找操作，返回值为所找到的元素的节点，若找不到则返回NULL，以所给参数为根节点开始查找
    template<typename T>
    BinTree<T>* BinTree<T>::Find_recurrence(T x,BinTree<T> *bt){
        if(!bt)return NULL;
        if(x>bt->val){
            return Find_recurrence(x,bt->right);
        } else if(x<bt->val){
            return Find_recurrence(x,bt->left);
        }else{
            return bt;
        }
    }
    template<typename T>
    BinTree<T>* BinTree<T>::Find_commone(T x,BinTree<T> * bt){
        if(!bt)return NULL;
        while (bt){
            if(x<bt->val){
                bt=bt->left;
            }else if(x>bt->val){
                bt=bt->right;
            }else{
                return bt;
            }
        }
    }

    //给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
    template<typename T>
    bool BinTree<T>::findTarget(BinTree<T>* root, int k) {
        BinTree<T> *temp;unordered_set<int>S;
        temp=root;
        queue<BinTree<T>*> Q;
        if(!temp)return false;
        Q.push(temp);
        while (!Q.empty()){
            temp=Q.front();
            Q.pop();
            if(S.count(k-(temp->val)))return true;
            S.insert(temp->val);
            if(temp->left){Q.push(temp->left);}
            if(temp->right){Q.push(temp->right);}
        }
        return false;

    }

    //给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    //百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    template<typename T>
    BinTree<T>* BinTree<T>::lowestCommonAncestor(BinTree<T>* p, BinTree<T>* q) {
        BinTree<T>* ancestor = this;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }

    //基于二叉搜索树找最大值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    template<typename T>
    BinTree<T>* BinTree<T>::FindMax_recurrence(BinTree<T>* bt){
        if(!bt)return NULL;
        else if(!bt->right)return bt;
        else if(bt->right)return FindMax_recurrence(bt->right);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMax_common(BinTree<T>* bt){
        if(bt){
            while (bt->right)bt=bt->right;
            return bt;
        }
        else if(bt==NULL){
            return  NULL;
        }
    }

    //基于二叉搜索树找最小值，若找到则返回其最大值的结点，若不存在则返回NULL,以所给参数为根结点进行查找
    template<typename T>
    BinTree<T>* BinTree<T>::FindMin_recurrence(BinTree<T>* bt){
        if(!bt)return NULL;
        else if(!bt->left)return bt;
        else if(bt->left)return FindMin_recurrence(bt->left);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMin_common(BinTree<T>* bt){
        if(bt){
            while (bt->left)bt=bt->left;
            return bt;
        }
        else if(bt==NULL){
            return  NULL;
        }
    }

    //基于二叉搜索树插入某个元素，需要给定二叉搜索树的根结点和所插入元素，返回值也是二叉搜索树的根结点,若插入的元素已经存在，返回NULL
    template<typename T>
    BinTree<T>* BinTree<T>::insert(T x,BinTree<T>* myself){
        if(!myself){
            myself =new BinTree<T>;
            myself->val=x;
        } else{
            if(x<myself->val){
                myself->left= insert(x,myself->left);
            } else if(x>myself->val){
                myself->right= insert(x,myself->right);
            } else if(x==myself->val){
                return NULL;
            }
        }
        return myself;
    }

    //基于二叉搜索树删除某个元素，需要给定二叉搜索树的根结点和所删除元素，返回值也是二叉搜索树的根结点
    template<typename T>
    BinTree<T>* BinTree<T>::delete_BinTree (T x,BinTree<T>* bt){
        if(!bt)cout<<"The element you want to delete doesn't exist!"<<endl;
        else if(x<bt->val){
            bt->left= delete_BinTree(x,bt->left);
        }else if(x>bt->val){
            bt->right= delete_BinTree(x,bt->right);
        }else if(x==bt->val){
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



