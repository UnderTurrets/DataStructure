#include "myalgorithm.h"

//数组类
    //判断一个数组中是否有相同元素
    bool containsDuplicate(vector<int>& nums) {
        bool ret=0;
        sort(nums.begin(),nums.end());
        for(int i= 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ret=1;
                break;
            }

        }
        return ret;
    }


    //寻找一个数组的最大子数组和
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],x=0;
        for (vector<int>::iterator it1=nums.begin();it1!=nums.end();it1++){
            x=max(x+(*it1),*it1);
            sum=max(x,sum);
        }

        return sum;
    }



//    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    vector<int> twoSum  (vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }



//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }



    //给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>::iterator it=nums2.begin();
        for (int i =0;i<nums1.size();i++){
            for ( ;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ret.insert(ret.end(),nums1[i]);
                    j++;
                    break;
                }
                if(nums1[i]<nums2[j]){
                    break;
                }
            }
        }
        return ret;
    }


//    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
    int maxProfit(vector<int>& prices) {
        int ret=0;int min=prices[0];
        for (vector<int>::iterator it=prices.begin();it!=prices.end();it++){
            if(*it<min){
                min=*it;
            }
            ret=max(ret,(*it)-min);
        }
        return ret;
    }

//    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//    给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
//    重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
//    如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if ((mat.size()*mat[0].size())==(r*c)){
            vector<int>cols(c,0);
            vector<vector<int>>des(r,cols);
            vector<int>line;
            int k=0;
            for(int i =0;i<mat.size();i++){
                for(int j =0;j<mat[i].size();j++){
                    line.insert(line.end(),mat[i][j]);
                }
            }
            for (int i=0;i<r;i++){
                for (int j=0;j<c;j++){
                    des[i][j]=line[k];
                    k++;
                }
            }
            return des;
        }else{
            return mat;
        }
    }

    //给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ret;vector<int>line ;
        for(int i =0;i<numRows;i++){
            line.resize(i+1,1);
            if(i>1){
                for(int j=1;j<i;j++){
                    line[j]=ret[i-1][j-1]+ret[i-1][j];
                }
            }
            ret.insert(ret.end(),line);
            line.clear();
        }
        return ret;
    }


    //请你判断一个9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
    //数字1-9在每一行只能出现一次。
    //数字1-9在每一列只能出现一次。
    //数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。（请参考示例图）
    bool find_repeat(vector<char> v){
        vector<char> nums;bool ret =1;int x=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>='0'&&v[i]<='9'){
                nums.push_back(v[i]);
            }
        }
        sort(nums.begin(),nums.end());
        if(!nums.empty()){
            for(int i= 0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]){
                    ret=0;
                    break;
                }
            }
        }
        return ret;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ret=1;bool x=1;
        for(int i=1;i<board.size();i+=3){
            for(int j=1;j<board[0].size();j+=3){
                x=find_repeat({board[i-1][j-1],board[i-1][j],board[i-1][j+1],board[i][j-1],board[i][j],board[i][j+1],board[i+1][j-1],board[i+1][j],board[i+1][j+1]});
                if(x==0){
                    ret=0;
                    break;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            x=find_repeat({board[0][i],board[1][i],board[2][i],board[3][i],board[4][i],board[5][i],board[6][i],board[7][i],board[8][i],});
            if(x==0){
                ret=0;
                break;
            }
            x=find_repeat({board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7],board[i][8],});
            if(x==0){
                ret=0;
                break;
            }
        }
        return ret;
    }


    //给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>input(matrix);
        for(int i=0;i<input.size();i++){
            for(int j=0;j<input[i].size();j++){
                if(input[i][j]==0){
                    for(int k=0;k<matrix[i].size();k++){
                        matrix[i][k]=0;
                    }
                    for(int k=0;k<matrix.size();k++){
                        matrix[k][j]=0;
                    }
                }
            }
        }
    }


//计时函数(请配置getTickCount函数对应的库，如opencv)
//void PrintMs ( ){
//    static short i =1;static long long last =0;
//    long long current=getTickCount();
//    if(i%2==1){
//        last =0;
//        cout<<"开始计时"<<endl;
//    }else{
//        i-=2;
//        cout<<"结束计时"<<endl;
//    }
//    if (last==0){
//        last = current;
//        i++;
//        return;
//    }
//    long long result = (double)((current-last)/getTickFrequency())*1000;
//    i++;
//    cout<<"间隔："<<result<<"ms"<<endl;
//}


//字符串
//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
int firstUniqChar(string s) {
    int ret=-1;
    for(int i=0;i<s.size();i++){
        int x=s.find(s[i]);
        int y=s.rfind(s[i]);
        if(x==y) {
            ret=i;
            break;
        }
    }
    return ret;
}

//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
bool canConstruct(string ransomNote, string magazine) {
        bool  ret=1;
        for(int i =0;i<ransomNote.size();i++){
            int x=magazine.find(ransomNote[i]);
            if(x!=-1){
                magazine.erase(x,1);
            }else if(x==-1){
                ret=0;
                break;
            }
        }
    return ret;
}

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。
bool isAnagram(string s, string t) {
    bool ret = 0;
    if(s.size()==t.size()) {
        ret=1;
            for (int i = 0; i < t.size(); i++) {
                int x = s.find(t[i]);
                if (x != -1) {
                    s.erase(x, 1);
                } else if (x == -1) {
                    ret = 0;
                    break;
                }
            }
        }
    return ret;
}





