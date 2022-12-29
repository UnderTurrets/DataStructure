#include "leetcode.h"
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



//    给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
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



//给你两个按 非递减顺序 排列的整数数组nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
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



//给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
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

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
int singleNumber(vector<int>& nums) {
    unordered_set<int> S;
    for(int i=0;i<nums.size();i++){
        if(S.count(nums[i])){
            S.erase(nums[i]);
        }else if(!S.count(nums[i])){
            S.insert(nums[i]);
        }
    }
    return *S.begin();
}

//给定一个大小为 n 的数组nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于⌊ n/2 ⌋的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
int majorityElement(vector<int>& nums) {
    unordered_map<int ,int > M;
    int ret=0;int times=0;
    for(int i=0;i<nums.size();i++){
        if(M.count(nums[i])) {
            M[nums[i]]++;
        }else if(!M.count(nums[i])){
            M[nums[i]]=1;
        }
        if(M[nums[i]]>times){
            times=M[nums[i]];
            ret=nums[i];
        }
    }
    return ret;
}

//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}

//    给定一个数组 prices ，它的第i 个元素prices[i] 表示一支给定股票第 i 天的价格。
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

//给定一个包含红色、白色和蓝色、共n 个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库内置的 sort 函数的情况下解决这个问题。
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            swap(nums[i], nums[ptr]);
            ++ptr;
        }
    }
    for (int i = ptr; i < n; ++i) {
        if (nums[i] == 1) {
            swap(nums[i], nums[ptr]);
            ++ptr;
        }
    }
}

//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({L, R});
        }
        else {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}

//给你一个整数数组nums ，判断这个数组中是否存在长度为 3 的递增子序列。
//如果存在这样的三元组下标 (i, j, k)且满足 i < j < k ，使得nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
bool increasingTriplet(vector<int>& nums){
    int min=nums[0],median=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<min){
            min=nums[i];
        }else if(nums[i]>min && nums[i]<median){
            median=nums[i];
        }else if(nums[i]>median){
            return true;
        }
    }
    return false;
}

//给你一个整数数组nums，返回 数组answer，其中answer[i]等于nums中除nums[i]之外其余各元素的乘积。
//题目数据 保证 数组nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内。
//请不要使用除法，且在O(n) 时间复杂度内完成此题。
vector<int> productExceptSelf(vector<int>& nums){
    int length = nums.size();
    vector<int> answer(length);

    // answer[i] 表示索引 i 左侧所有元素的乘积
    // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
    answer[0] = 1;
    for (int i = 1; i < length; i++) {
        answer[i] = nums[i - 1] * answer[i - 1];
    }

    // R 为右侧所有元素的乘积
    // 刚开始右边没有元素，所以 R = 1
    int R = 1;
    for (int i = length - 1; i >= 0; i--) {
        // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
        answer[i] = answer[i] * R;
        // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
        R *= nums[i];
    }
    return answer;
}

//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
int subarraySum(vector<int>& nums, int k){
    unordered_map<int, int> mp;
    mp.insert(make_pair(0,1));
    int ret = 0, sum = 0;
    for (int i=0;i<nums.size();i++) {
        sum += nums[i];
        if (mp.find(sum - k) != mp.end()) {
            ret += mp[sum - k];
        }
        mp.insert(make_pair(sum,0));
        mp[sum]++;
    }
    return ret;
}

//    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//    给你一个由二维数组 mat 表示的m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
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

//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
vector<vector<int>> generateMatrix(int n) {
    int maxNum = n * n;
    int curNum = 1;
    vector<vector<int>> matrix(n, vector<int>(n));
    int row = 0, column = 0;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
    int directionIndex = 0;
    while (curNum <= maxNum) {
        matrix[row][column] = curNum;
        curNum++;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
            directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
        }
        row = row + directions[directionIndex][0];
        column = column + directions[directionIndex][1];
    }
    return matrix;
}

//给定一个 n×n 的二维矩阵matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}

//编写一个高效的算法来搜索mxn矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++){
        if(matrix[i].front()<=target && matrix[i].back()>=target){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target)return true;
            }
        }else{
            continue;
        }
    }
    return false;
}

//给定一个区间的集合intervals，其中 intervals[i] = [starti, endi]。返回 需要移除区间的最小数量，使剩余区间互不重叠。
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[1] < v[1];
    });
    int n = intervals.size();
    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] >= right) {
            ++ans;
            right = intervals[i][1];
        }
    }
    return n - ans;
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

//给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
bool isValid(string s) {
    if (s.size() % 2 != 0)return false;

    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    stack<char> stk;
    for (int i =0;i<s.size();i++) {
        if (pairs.count(s[i])) {
            if (stk.empty() || stk.top() != pairs[s[i]]) {
                return false;
            }
            stk.pop();
        }
        else {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

//给定两个字符串形式的非负整数num1 和num2，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger），也不能直接将输入的字符串转换为整数形式。
string addStrings(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans.push_back('0' + result % 10);
        add = result / 10;
        i -= 1;
        j -= 1;
    }
    // 计算完以后的答案需要翻转过来
    reverse(ans.begin(), ans.end());
    return ans;
}

//给定一个包含大写字母和小写字母的字符串s，返回通过这些字母构造成的 最长的回文串。
//在构造过程中，请注意 区分大小写 。比如"Aa"不能当做一个回文字符串。
int longestPalindrome(string s) {
    unordered_map<char,int>M;int pairNumber=0,ret =0;
    for(string::iterator it= s.begin();it!=s.end();it++){
        M[*it]++;
        if(M[*it]%2==0){
            pairNumber++;
        }
    }
    ret= pairNumber*2;
    for(string::iterator it= s.begin();it!=s.end();it++){
        if(M[*it]%2==1){
            ret++;
            break;
        }
    }
    return ret;
}

//链表
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool operator< (ListNode that){
        return this->val<=that.val;
    }
    bool operator> (ListNode that){
        return this->val>=that.val;
    }
};

//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递。仅仅是为了标识链表的实际情况。
//如果链表中存在环，则返回 true 。 否则，返回 false 。
bool hasCycle(ListNode *head){
    bool ret=0;
    if(head){
        unordered_set<ListNode*>temp;
        while (head->next){
            if(temp.count(head)){
                ret=1;
                break;
            }
            temp.insert(temp.end(),head);
            head=head->next;
        }
    }
    return ret;
}

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1==NULL)return  list2;
    if(list2==NULL)return  list1;
    if(list1->val<list2->val){
        list1->next= mergeTwoLists(list1->next,list2);
        return list1;
    }else{
        list2->next= mergeTwoLists(list1,list2->next);
        return  list2;
    }
}

//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
ListNode* removeElements(ListNode* head, int val){
    if (head == nullptr) {
        return head;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
ListNode* deleteDuplicates(ListNode* head) {
    if(!head) {
        return NULL;
    }else if(!head->next) {
        return head;
    }
    head->next= deleteDuplicates(head->next);
    if(head->val==head->next->val) {
        return head->next;
    }else {
        return head;
    }
}

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
ListNode* reverseList(ListNode* head) {
    ListNode* last=NULL;
    while (head){
        ListNode* next=head->next;
        head->next=last;
        last=head;
        head=next;
    }
    return last;
}

//不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
//实现 MyHashMap 类：
//MyHashMap() 用空映射初始化对象
//void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
//int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
//void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
class MyHashMap {
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap(): data(base) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        data[h].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it).first == key) {
                data[h].erase(it);
                return;
            }
        }
    }
};