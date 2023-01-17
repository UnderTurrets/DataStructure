#ifndef __leetcode_h__
#define __leetcode_h__


#include "authority.h"

//判断一个数组中是否有相同元素
static bool containsDuplicate(vector<int>& nums);

//寻找一个数组的最大子数组和
static int maxSubArray(vector<int>& nums);

//    给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
//    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
static vector<int> twoSum  (vector<int>& nums, int target);

//给你两个按 非递减顺序 排列的整数数组nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
static vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
static int singleNumber(vector<int>& nums);

//给定一个大小为 n 的数组nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于⌊ n/2 ⌋的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
static int majorityElement(vector<int>& nums);

//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
static vector<vector<int>> threeSum(vector<int>& nums);

//    给定一个数组 prices ，它的第i 个元素prices[i] 表示一支给定股票第 i 天的价格。
//    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
static int maxProfit(vector<int>& prices);

//给定一个包含红色、白色和蓝色、共n 个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库内置的 sort 函数的情况下解决这个问题。
static void sortColors(vector<int>& nums);

//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
static vector<vector<int>> merge(vector<vector<int>>& intervals);

//给你一个整数数组nums ，判断这个数组中是否存在长度为 3 的递增子序列。
//如果存在这样的三元组下标 (i, j, k)且满足 i < j < k ，使得nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
static bool increasingTriplet(vector<int>& nums);

//给你一个整数数组nums，返回 数组answer，其中answer[i]等于nums中除nums[i]之外其余各元素的乘积。
//题目数据 保证 数组nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内。
//请不要使用除法，且在O(n) 时间复杂度内完成此题。
static vector<int> productExceptSelf(vector<int>& nums);

//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
static int subarraySum(vector<int>& nums, int k);

//    在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
//    给你一个由二维数组 mat 表示的m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
//    重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
//    如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
static vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
static vector<vector<int>> generate(int numRows);

//请你判断一个9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//数字1-9在每一行只能出现一次。
//数字1-9在每一列只能出现一次。
//数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。（请参考示例图）
static bool find_repeat(vector<char> v);
static bool isValidSudoku(vector<vector<char>>& board);

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
static void setZeroes(vector<vector<int>>& matrix);

//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
static vector<vector<int>> generateMatrix(int n);

//给定一个 n×n 的二维矩阵matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
static void rotate(vector<vector<int>>& matrix);

//编写一个高效的算法来搜索mxn矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
static bool searchMatrix(vector<vector<int>>& matrix, int target);

//给定一个区间的集合intervals，其中 intervals[i] = [starti, endi]。返回 需要移除区间的最小数量，使剩余区间互不重叠。
static int eraseOverlapIntervals(vector<vector<int>>& intervals);







//字符串
//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
static int firstUniqChar(string s);

//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
static bool canConstruct(string ransomNote, string magazine);

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。
static bool isAnagram(string s, string t);

//给定两个字符串形式的非负整数num1 和num2，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger），也不能直接将输入的字符串转换为整数形式。
static string addStrings(string num1, string num2);

//给定一个包含大写字母和小写字母的字符串s，返回通过这些字母构造成的 最长的回文串。
//在构造过程中，请注意 区分大小写 。比如"Aa"不能当做一个回文字符串。
static int longestPalindrome(string s);

//给定一种规律 pattern和一个字符串s，判断 s是否遵循相同的规律。
//这里的遵循指完全匹配，例如，pattern里的每个字母和字符串s中的每个非空单词之间存在着双向连接的对应规律。
static bool wordPattern(string pattern, string s);

//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
//注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
//返回一个表示每个字符串片段的长度的列表。
static vector<int> partitionLabels(string s);

//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
static vector<vector<string>> groupAnagrams(vector<string>& strs);

//给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
static string multiply(string num1, string num2);

//DNA序列由一系列核苷酸组成，缩写为'A','C','G'和'T'.。
//例如，"ACGAATTCCG"是一个 DNA序列 。
//在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的长度为10的序列(子字符串)。你可以按 任意顺序 返回答案。
static vector<string> findRepeatedDnaSequences(string s);

//给你一个字符串 s，找到 s 中最长的回文子串。
//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
static string longestPalindrome_subseries(string s);








//链表
//链表定义
class ListNode {
public:
    int val;
    ListNode *next;
    inline ListNode() : val(0), next(nullptr) {}
    inline ListNode(const int x) : val(x), next(nullptr) {}
    inline ListNode(const int x, ListNode *next) : val(x), next(next) {}
    inline bool operator< (const ListNode that);
    inline bool operator> (const ListNode that);
};

//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：valV_front和V_frontnext。valV_front是当前节点的值，nextV_front是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性V_frontprevV_front以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
//在链表类中实现这些功能：
//get(index)：获取链表中第V_frontindexV_front个节点的值。如果索引无效，则返回-1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为V_frontvalV_front的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为V_frontval 的节点追加到链表的最后一个元素。
//addAtIndex(index,val)：在链表中的第V_frontindexV_front个节点之前添加值为V_frontvalV_front 的节点。如果V_frontindexV_front等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引V_frontindex 有效，则删除链表中的第V_frontindex 个节点。
class MyLinkedList {

public:

    inline MyLinkedList();

    int get(int index);

    inline void addAtHead(int val);

    void addAtTail(int val);

    void addAtIndex(int index, int val);

    void deleteAtIndex(int index);

private:

    int size;
    ListNode *head;

};

//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递。仅仅是为了标识链表的实际情况。
//如果链表中存在环，则返回 true 。 否则，返回 false 。
// Definition for singly-linked list.
static bool hasCycle(ListNode *head);

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
static ListNode* removeElements(ListNode* head, int val);

//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
static ListNode* deleteDuplicates(ListNode* head);

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
static ListNode* reverseList(ListNode* head);

//给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0开头。
static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。
static ListNode *detectCycle(ListNode *head);

//给你两个单链表的头节点headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。
static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
static ListNode* deleteDuplicates_all(ListNode* head);

//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
static ListNode* swapPairs(ListNode* head);

//给你链表的头节点 head ，每k个节点一组进行翻转，请你返回修改后的链表。
//k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
static ListNode* reverseKGroup(ListNode* head, int k);

//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
static void reorderList(ListNode* head);










//栈
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(T x) 将元素 x 推到队列的末尾
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
    inline MyQueue<T>();

    __attribute__((unused)) void push(T x);

    inline T pop();

    inline T peek();

    inline bool empty();
};

//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类:
//MinStack() 初始化堆栈对象。
//void push(T val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//T top() 获取堆栈顶部的元素。
//T getMin() 获取堆栈中的最小元素。
template<typename T>
class MinStack {
public:
    MinStack();

    inline void push(T val);

    inline void pop();

    inline T top();

    inline T getMin();

private:
    stack<T> S;
    stack<T>min;
};

//给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
static bool isValid(string s);

//给你一个由 '('、')' 和小写字母组成的字符串 s。
//你需要从字符串中删除最少数目的 '(' 或者 ')'（可以删除任意位置的括号)，使得剩下的「括号字符串」有效。
//请返回任意一个合法字符串。
//有效「括号字符串」应当符合以下任意一条要求：
//空字符串或只包含小写字母的字符串
//可以被写作AB（A连接B）的字符串，其中A和B都是有效「括号字符串」
//可以被写作(A)的字符串，其中A是一个有效的「括号字符串」
static string minRemoveToMakeValid(string s);









//队列
//共有 n 名小伙伴一起做游戏。小伙伴们围成一圈，按 顺时针顺序 从 1 到 n 编号。确切地说，从第 i 名小伙伴顺时针移动一位会到达第 (i+1) 名小伙伴的位置，其中 1 <= i < n ，从第 n 名小伙伴顺时针移动一位会回到第 1 名小伙伴的位置。
//游戏遵循如下规则：
//从第 1 名小伙伴所在位置 开始 。
//沿着顺时针方向数 k 名小伙伴，计数时需要 包含 起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。
//你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。
//如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 顺时针下一位 小伙伴 开始，回到步骤 2 继续执行。
//否则，圈子中最后一名小伙伴赢得游戏。
//给你参与游戏的小伙伴总数 n ，和一个整数 k ，返回游戏的获胜者。
static int findTheWinner(int n, int k);








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
    static int hash(int key);
public:
    /** Initialize your data structure here. */
    inline MyHashMap() ;

    /** value will always be non-negative. */
    inline void put(int key, int value) ;

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) ;

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key);

};





//图
//小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。
//如果小镇法官真的存在，那么：
//小镇法官不会信任任何人。
//每个人（除了小镇法官）都信任这位小镇法官。
//只有一个人同时满足属性 1 和属性 2 。
//给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。
//如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。
static int findJudge(int n, vector<vector<int>>& trust);

//给你一个 有向无环图， n个节点编号为 0到 n-1，以及一个边数组 edges，其中 edges[i] = [fromi, toi]表示一条从点fromi到点toi的有向边。
//找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。
//你可以以任意顺序返回这些节点编号。
static vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);

//有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。
//当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。
//给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。
static bool canVisitAllRooms(vector<vector<int>>& rooms);






//优先队列
//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
static int findKthLargest(vector<int>& nums, int k);

//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
static vector<int> topKFrequent(vector<int>& nums, int k);

//给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
//返回 已排序的字符串。如果有多个答案，返回其中任何一个。
static string frequencySort(string s);

//给定一个数组 points，其中points[i] = [xi, yi]表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。
//这里，平面上两点之间的距离是欧几里德距离（√(x1- x2)2+ (y1- y2)2）。
//你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。
static vector<vector<int>> kClosest(vector<vector<int>>& points, int k);





#endif