#include "Tree.h"

//树
template<typename T>
BinTree<T>::BinTree(){
    val;
    this->left=nullptr;
    this->right=nullptr;
}

template<typename T>
BinTree<T>::BinTree( T x){
    this->val=x;
    this->left=nullptr;
    this->right=nullptr;
}

//给你一个整数数组 nums ，请你将其转换为一棵 高度平衡 二叉搜索树。
//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
template<typename T>
BinTree<T>::BinTree(vector<T> nums){
    sort(nums.begin(),nums.end());
    this->val=sortedArrayToBST_helper(nums,0,nums.size()-1)->val;
    this->left=sortedArrayToBST_helper(nums,0,nums.size()-1)->left;
    this->right=sortedArrayToBST_helper(nums,0,nums.size()-1)->right;
}
template<typename T>
BinTree<T>* BinTree<T>::sortedArrayToBST_helper(vector<T> nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    // 总是选择中间位置左边的数字作为根节点
    int mid = (left + right) / 2;
    BinTree<T>* root = new BinTree<T>(nums[mid]);
    root->left = sortedArrayToBST_helper(nums, left, mid - 1);
    root->right = sortedArrayToBST_helper(nums, mid + 1, right);
    return root;
}

//给定两个整数数组preorder 和 inorder，其中preorder 是二叉树的先序遍历， inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。
//1 <= preorder.length <= 3000
//inorder.length == preorder.length
//-3000 <= preorder[i], inorder[i] <= 3000
//preorder和inorder均 无重复 元素
//inorder均出现在preorder
//preorder保证 为二叉树的前序遍历序列
//inorder保证 为二叉树的中序遍历序列
template<typename T>
BinTree<T>::BinTree(vector<T> preorder, vector<T> inorder) {
    this->val=preorder[0];
    stack<BinTree<T>*> stk;
    stk.push(this);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i) {
        int preorderVal = preorder[i];
        BinTree<T>* node = stk.top();
        if (node->val != inorder[inorderIndex]) {
            node->left = new BinTree<T>(preorderVal);
            stk.push(node->left);
        }
        else {
            while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                node = stk.top();
                stk.pop();
                ++inorderIndex;
            }
            node->right = new BinTree<T>(preorderVal);
            stk.push(node->right);
        }
    }
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
                S.push(nullptr);
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

    //按先序顺序把二叉树转为数组
    template<typename T>
    vector<T> BinTree<T>::preorder_BT2VECTOR(){
        stack<BinTree<T>*> S;vector<T>ret;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                if(temp->right)S.push(temp->right);
                if(temp->left)S.push(temp->left);
                S.push(temp);
                S.push(nullptr);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                ret.push_back(temp->val);
                //在此以上进行你要执行的操作
            }
        }
        return ret;
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
                S.push(nullptr);
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

    //按中序顺序把二叉树转为数组
    template<typename T>
    vector<T> BinTree<T>::inorder_BT2VECTOR(){
        stack<BinTree<T>*> S;vector<T>ret;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                if(temp->right)S.push(temp->right);
                S.push(temp);
                S.push(nullptr);
                if(temp->left)S.push(temp->left);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                ret.push_back(temp->val);
                //在此以上进行你要执行的操作
            }
        }
        return ret;
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
                S.push(nullptr);
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

    //按后序顺序把二叉树转为数组
    template<typename T>
    vector<T> BinTree<T>::postorder_BT2VECTOR(){
        stack<BinTree<T>*> S;vector<T>ret;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                S.push(temp);
                S.push(nullptr);
                if(temp->right)S.push(temp->right);
                if(temp->left)S.push(temp->left);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                ret.push_back(temp->val);
                //在此以上进行你要执行的操作
            }
        }
        return ret;
    }

    //层序遍历
    template<typename T>
    void BinTree<T>::Travesal_levelorder(){
        BinTree<T> *temp;
        temp=this;
        queue<BinTree<T>*> Q;
        Q.push(temp);
        while (!Q.empty()){
            temp=Q.front();
            Q.pop();
            //在此进行你要执行的操作

            cout<<temp->val<<" ";

            //在此以上进行你要执行的操作
            if(temp->left){Q.push(temp->left);}
            if(temp->right){Q.push(temp->right);}
        }
        cout<<endl;
    }

    //按层形成二维数组（层序遍历的应用）
    template<typename T>
    vector<vector<T>> BinTree<T>::levelOrder() {
        vector<vector<T>>ret;
        queue<BinTree<T>*> Q;
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

    //给你二叉树的根节点 this ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
    template<typename T>
    vector<vector<T>> BinTree<T>::zigzagLevelOrder(){
        vector<vector<T>>ret;
        queue<BinTree<T>*> Q;
        Q.push(this);
        int flag=0;
        while (!Q.empty()){
            int x=Q.size();
            flag++;
            ret.push_back(vector<int>());
            for(int i=0;i<x;i++){
                auto node=Q.front();Q.pop();
                ret.back().push_back(node->val);
                if(node->left){Q.push(node->left);}
                if(node->right){Q.push(node->right);}
            }
            if(flag%2==0)reverse(ret.back().begin(),ret.back().end());
        }
        return ret;
    }

    //先序遍历递归，以所给参数为根节点开始遍历
    template<typename T>
    void BinTree<T>::Travesal_preorder_recurrence_helper (BinTree<T> *root){
        if(root){
            //在此进行你要执行的操作
            cout<<root->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_preorder_recurrence_helper(root->left);
            Travesal_preorder_recurrence_helper(root->right);
        }
        return;
    }
    template<typename T>
    void BinTree<T>::Travesal_preorder_recurrence(){
        this->Travesal_preorder_recurrence_helper(this);
        return;
    }

    //中序遍历递归，以所给参数为根节点开始遍历
    template<typename T>
    void BinTree<T>::Travesal_inorder_recurrence_helper (BinTree<T> *root){
        if(root){
            Travesal_inorder_recurrence_helper(root->left);
            //在此进行你要执行的操作
            cout<<root->val<<endl;




            //在此以上进行你要执行的操作
            Travesal_inorder_recurrence_helper(root->right);
        }
    }
    template<typename T>
    void BinTree<T>::Travesal_inorder_recurrence(){
        this->Travesal_inorder_recurrence_helper(this);
    }

    //后序遍历递归，以所给参数为根节点开始遍历
    template<typename T>
    void BinTree<T>::Travesal_postorder_recurrence_helper (BinTree<T> *root){
        if(root){
            Travesal_postorder_recurrence_helper(root->left);
            Travesal_postorder_recurrence_helper(root->right);
            //在此进行你要执行的操作
            cout<<root->val<<endl;




            //在此以上进行你要执行的操作
        }
    }
    template<typename T>
    void BinTree<T>::Travesal_postorder_recurrence(){
        this->Travesal_postorder_recurrence_helper(this);
    }

    //给定一个二叉树的 根节点 this，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
    template<typename T>
    vector<T> BinTree<T>::rightSideView(){
        vector<T>ret;
        queue<BinTree<T>*> Q;
        Q.push(this);
        while (!Q.empty()){
            int x=Q.size();
            for(int i=0;i<x;i++){
                BinTree<T>* node=Q.front();Q.pop();
                if(i==x-1)ret.push_back(node->val);
                if(node->left){Q.push(node->left);}
                if(node->right){Q.push(node->right);}
            }
        }
        return ret;
    }

    //得到树的高度，以所给参数为根节点开始计算高度
    template<typename T>
    int BinTree<T>::GetHeight_helper(BinTree<T> *root){
        int heifht_left,height_right,height;
        if(root){
            heifht_left=GetHeight_helper(root->left);
            height_right=GetHeight_helper(root->right);
            height= max(heifht_left,height_right);
            return (height+1);
        } else{
            return 0;
        }
    }
    template<typename T>
    int BinTree<T>::GetHeight(){
        return this->GetHeight_helper(this);
    }

    //检验对称二叉树
    template<typename T>
    inline bool BinTree<T>::IsSymmetric(){
        return IsSymmetric_helper(this, this);
    }
    template<typename T>
    bool BinTree<T>::IsSymmetric_helper(BinTree<T>root1,BinTree<T>root2){
        BinTree<T>* p= this;
        BinTree<T>* q= this;
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && IsSymmetric_helper(p->left, q->right) && IsSymmetric_helper(p->right, q->left);
    }


    //翻转二叉树
    template<typename T>
    BinTree<T>* BinTree<T>::InvertTree_helper(BinTree<T>* root){
        if (root == nullptr) {
            return nullptr;
        }
        BinTree<T>* bt1 = InvertTree_helper(root->left);
        BinTree<T>* bt2 = InvertTree_helper(root->right);
        root->left = bt2;
        root->right = bt1;
        return root;
    }
    template<typename T>
    void BinTree<T>::InvertTree(){
        this->InvertTree_helper(this);
    }

    //给你二叉树的根节点root 和一个表示目标和的整数targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
    template<typename T>
    bool BinTree<T>::hasPathSum_helper(BinTree<T>* root, T targetSum) {
        if(!root)return false;
        if(!root->left && !root->right)return targetSum==root->val;
        return hasPathSum_helper(root->left,targetSum-root->val) || hasPathSum_helper(root->right,targetSum-root->val);
    }
    template<typename T>
    bool BinTree<T>::hasPathSum(T targetSum) {
        return hasPathSum_helper(this,targetSum);
    }

    //给你二叉树的根节点 this 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
    template<typename T>
    void BinTree<T>::pathSum_helper(BinTree<T>*root,T targetSum,vector<vector<T>>&ret,vector<T>&path){
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ret.emplace_back(path);
        }
        pathSum_helper(root->left, targetSum,ret,path);
        pathSum_helper(root->right, targetSum,ret,path);
        path.pop_back();
    }
    template<typename T>
    vector<vector<T>> BinTree<T>::pathSum(T targetSum){
        vector<vector<T>>ret;vector<T>path;
        this->pathSum_helper(this,targetSum,ret,path);
        return ret;
    }

    //给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
    template<typename T>
    bool BinTree<T>::IsValidBST_helper(BinTree<T>* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return IsValidBST_helper(root -> left, lower, root -> val) && IsValidBST_helper(root -> right, root -> val, upper);
    }
    template<typename T>
    bool BinTree<T>::IsValidBST() {
        return IsValidBST_helper(this, LONG_MIN, LONG_MAX);
    }

    //基于二叉搜索树的查找操作，返回值为所找到的元素的节点，若找不到则返回nullptr，以所给参数为根节点开始查找
    template<typename T>
    BinTree<T>* BinTree<T>::Find_recurrence_helper(T x,BinTree<T> *root){
        if(!root){
            cout<<"The element you want to find doesn't exist and your operation has failed!(nullptr has been returned)"<<endl;
            return nullptr;
        }
        if(x>root->val){
            return Find_recurrence_helper(x,root->right);
        } else if(x<root->val){
            return Find_recurrence_helper(x,root->left);
        }else if(x==root->val){
            return root;
        }
    }
    template<typename T>
    BinTree<T>* BinTree<T>::Find_recurrence(T x){
        return this->Find_recurrence_helper(x,this);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::Find_common(T x){
        BinTree<T>* temp= this;
        while (temp){
            if(x<temp->val){
                temp=temp->left;
            }else if(x>temp->val){
                temp=temp->right;
            }else if(x==temp->val){
                return temp;
            }
        }
        cout<<"The element you want to find doesn't exist and your operation has failed!(nullptr has been returned)"<<endl;
        return nullptr;
    }

    //给定一个二叉搜索树的根节点 this ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
    template<typename T>
    T BinTree<T>::kthSmallest(int k){
        stack<BinTree<T>*> S;int flag=1;
        if(this)S.push(this);
        while (!S.empty()){
            BinTree<T>* temp=S.top();
            if(temp){
                S.pop();
                if(temp->right)S.push(temp->right);
                S.push(temp);
                S.push(nullptr);
                if(temp->left)S.push(temp->left);
            }else{
                S.pop();
                temp=S.top();
                S.pop();
                //在此进行你要执行的操作
                cout<<temp->val<<endl;
                if(flag==k)return temp->val;
                flag++;
                //在此以上进行你要执行的操作
            }
        }
        if(flag<k){
            cout<<"This tree doesn't have enough elements and your operation has failed!(the element of the root has been returned)"<<endl;
        }
        return this->val;
    }

    //给定一个二叉搜索树 this 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
    template<typename T>
    bool BinTree<T>::findTarget(T k) {
        BinTree<T> *temp;unordered_set<int>S;
        temp=this;
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
    BinTree<T>* BinTree<T>::lowestCommonAncestorBST(T p, T q) {
        BinTree<T>* ancestor = this;
        while (true) {
            if (p < ancestor->val && q < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p > ancestor->val && q > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
template<typename T>
BinTree<T>* BinTree<T>::lowestCommonAncestorBST(BinTree<T>* p, BinTree<T>* q) {
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

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
template<typename T>
BinTree<T>* BinTree<T>::lowestCommonAncestor_helper(BinTree<T>* root, T p, T q) {
    if(root == nullptr || root->val == p || root->val== q) return root;
    BinTree<T> *le = lowestCommonAncestor_helper(root->left, p, q);
    BinTree<T> *ri = lowestCommonAncestor_helper(root->right, p, q);
    if(le == nullptr) return ri;
    if(ri == nullptr) return le;
    return root;
}
template<typename T>
BinTree<T>* BinTree<T>::lowestCommonAncestor( T p, T q) {
    return  lowestCommonAncestor_helper(this, p, q);
}
template<typename T>
BinTree<T>* BinTree<T>::lowestCommonAncestor( BinTree<T>* p, BinTree<T>* q) {
    return  lowestCommonAncestorX_helper(this, p->val, q->val);
}

    //基于二叉搜索树找最大值，返回其最大值的结点,以根结点进行查找
    template<typename T>
    BinTree<T>* BinTree<T>::FindMax_recurrence_helper(BinTree<T>* root){
        if(!root->right)return root;
        else if(root->right)return FindMax_recurrence_helper(root->right);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMax_recurrence(){
        return this->FindMax_recurrence_helper(this);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMax_common(){
        BinTree<T>*temp=this;
        if(temp){
            while (temp->right)temp=temp->right;
        }
        return temp;
    }

    //基于二叉搜索树找最小值，返回其最大值的结点,以根结点进行查找
    template<typename T>
    BinTree<T>* BinTree<T>::FindMin_recurrence_helper(BinTree<T>* root){
        if(!root->left)return root;
        else if(root->left)return FindMin_recurrence_helper(root->left);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMin_recurrence(){
        return this->FindMin_recurrence_helper(this);
    }
    template<typename T>
    BinTree<T>* BinTree<T>::FindMin_common(){
        BinTree<T>*temp=this;
        if(temp){
            while (temp->left)temp=temp->left;
        }
        return temp;
    }

    //基于二叉搜索树插入某个元素，需要给定所插入元素，返回值是插入后二叉搜索树的根结点,若插入的元素已经存在，返回nullptr
    template<typename T>
    BinTree<T>* BinTree<T>::insert_helper(T x,BinTree<T>* root){
        if(!root){
            root =new BinTree<T>;
            root->val=x;
        } else{
            if(x<root->val){
                root->left= insert_helper(x,root->left);
            } else if(x>root->val){
                root->right= insert_helper(x,root->right);
            } else if(x==root->val){
                cout<<"The element you want to insert has existed and your operation has failed!(nullptr has been returned)"<<endl;
                return nullptr;
            }
        }
        return root;
    }
    template<typename T>
    BinTree<T>* BinTree<T>::insert(T x){
        return this->insert_helper(x,this);
    }

    //基于二叉搜索树删除某个元素，需要给定所删除元素，返回值是删除后二叉搜索树的根结点,若删除的元素不存在，返回nullptr
    template<typename T>
    BinTree<T>* BinTree<T>::delete_bt_helper ( T x, BinTree<T>* root ){
        if( !root )cout<<"The element you want to delete doesn't exist and your operation has failed!(nullptr has been returned)"<<endl;
        else if( x < root->val ){
            root->left = delete_bt_helper(x,root->left);
        }else if( x > root->val ){
            root->right = delete_bt_helper(x,root->right);
        }else if( x == root->val ){
            if( root->left && root->right ){
                BinTree<T> * temp = root->right->FindMin_common();
                root->val = temp->val;
                root->right = delete_bt_helper(temp->val,root->right);
            }else{
                if( !root->left ){
                    BinTree<T> * temp=root->right;
                    root->val=temp->val;
                    root->left=temp->left;
                    root->right=temp->right;
                }
                else if( !root->right ){
                    BinTree<T> * temp=root->left;
                    root->val=temp->val;
                    root->left=temp->left;
                    root->right=temp->right;
                }
            }
        }
        return root;
    }
    template<typename T>
    BinTree<T>* BinTree<T>::delete_bt(T x){
        return this->delete_bt_helper(x,this);
    }

//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
//请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
// Encodes a tree to a single string.
template<typename T>
string BinTree<T>::serialize2String() {
    queue<BinTree<T>*> q;
    string ans;
    q.push(this);
    while(!q.empty()){
        BinTree<T>* node = q.front();
        q.pop();
        if(node != nullptr){
            ans += to_string(node->val) + ',';
            q.push(node->left);
            q.push(node->right);
        }
        else ans += "#,";
    }
    return ans;
}
// Decodes your encoded data to tree.
template<typename T>
BinTree<T>* Vector2BT(vector<BinTree<T>*>& v){
/* 在反序列化时，既用到了节点数组v，又用到了队列q。两者都是层序，但v存储null，q不存储null
 * 对于示例一：[1,2,3,null,null,4,5] ---- v = [1,2,3,null,null,4,5,null,null,null,null], q = [1,2,3,4,5]
 * 而对于示例二：[1,null,3,4,5] ---- v = [1,null,3,4,5,null,null,null,null], q = [1,3,4,5]
 * 不难发现：1. v.size == 2 * q.size() + 1;
 *           2. q[i]的左孩子是v[2*i+1],右孩子是v[2*i+2];
 *           3. v中非空节点的顺序与q中一样
 *  由以上三点，初始化变量cur为1，在v中每次移动两步，而q每次取一个值相当于移动一步即可*/
    queue<BinTree<T>*> q;
    q.push(v[0]);
    int cur = 1, sz = v.size();
    while(cur < sz){
        auto node = q.front();
        q.pop();
        if(v[cur] != nullptr){
            // 由上述第三点，直接在遍历数组v的时候就可以形成不包含null的层序遍历结果q
            q.push(v[cur]);
            node->left = v[cur];
        }
        if(v[cur + 1] != nullptr){
            q.push(v[cur + 1]);
            node->right = v[cur + 1];
        }
        cur += 2;
    }
    return v[0];
}
template<typename T>
BinTree<T>* deserialize2BT(string data) {
    if(data[0] == '#') return nullptr;   // 特判
    // 将序列化结果转化为节点vector（包含null）
    vector<BinTree<T>*> v;
    string str;
    for(auto& c: data){
        str.push_back(c);
        // 按逗号分隔开
        if(c == ','){
            str.pop_back();
            if(str == "#") v.emplace_back(nullptr);
            else{
                // 新建节点
                BinTree<T>* tmp = new BinTree<T>(stoi(str));
                v.emplace_back(tmp);
            }
            str.clear();
        }
    }
    return Vector2BT<T>(v);
}





//树的中序迭代器
    //重载运算符
    template<typename T>
    InOrderBtIter<T> InOrderBtIter<T>::operator= (InOrderBtIter<T> that){
        this->target=that.target;
        this->S=that.S;
    }
    template<typename T>
    InOrderBtIter<T> InOrderBtIter<T>::operator++ (){
        this->next();
        return this;
    }
    template<typename T>
    T InOrderBtIter<T>::operator* (){
        this->target = this->S.top();
        return this->target->val;
    }

    template<typename T>
    InOrderBtIter<T>::InOrderBtIter() {
        this->target= nullptr;
        while (!this->S.empty())this->S.pop();
    }
    template<typename T>
    InOrderBtIter<T>::InOrderBtIter(BinTree<T>* root) {
        this->target=root;
        while (this->target){
            this->S.push(this->target);
            this->target=this->target->left;
        }
    }

    template<typename T>
    T InOrderBtIter<T>::next() {
        if(hasNext()) {
            this->target = this->S.top();
            this->S.pop();
            BinTree<T> *des = this->target;
            if (this->target->right) {
                this->target = this->target->right;
                while (this->target) {
                    this->S.push(this->target);
                    this->target = this->target->left;
                }
            }
            return des->val;
        }else{
            cout<<"The tree doesn't have next element and your operation has failed!(the last element has been returned)"<<endl;
            return this->target->val;
        }
    }

    template<typename T>
    bool InOrderBtIter<T>::hasNext() {
        return !this->S.empty();
    }




