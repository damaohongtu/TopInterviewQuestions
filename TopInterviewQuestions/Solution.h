#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <string>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

/******************************数组**********************************************/
class RemoveDuplicates {
public:
	//有两个要求，1要移除重复的元素，这里使用了unique函数
	//使用distance函数返回长度
	//之所以传引用是因为要移除元素
	int removeDuplicates01(vector<int> &nums) {
		if (nums.size()==0 ) {
			return 0;
		}
		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[index]!=nums[i])
			{
				nums[++index] = nums[i];
			}
		}
		return index+1;
	}
public:
	int removeDuplicates02(const vector<int> &nums) {
		//unique而返回值是去重之后的尾地址
		vector<int > tmp = nums;
		return distance(tmp.begin(), unique(tmp.begin(),tmp.end()));
	}
};

//针对于无序的进行排序
class RemoveDuplicatesII {
public:
	int solution(vector <int> &nums) {
		if (nums.empty())
		{
			return 0;
		}
		map<int, int> num_count;
		for (size_t i = 0; i < nums.size(); i++)
		{
			num_count[nums[i]]++;
		}
		return num_count.size();
	}
};

class TwoSum {
public:
	vector<int>twoSum(vector<int>&nums,int target) {
		unordered_map<int, int>mapping;
		vector<int>result;
		for (size_t i = 0; i < nums.size(); i++)
		{
			mapping[nums[i]] = i;
		}
		for (size_t i = 0; i < nums.size(); i++)
		{
			const int gap = target - nums[i];
			if (mapping.find(gap)!=mapping.end()&&mapping[gap]>i)
			{
				result.push_back(i);
				result.push_back(mapping[gap]);
				break;
			}
			return result;
		}
	}
};

class RotateImage {
public:
	void rotate(vector<vector<int>>&matrix) {
		const int n = matrix.size();
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n-i; j++)
			{
				swap(matrix[i][j],matrix[n-1-j][n-1-i]);
			}
		}
		for (size_t i = 0; i < n/2; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				swap(matrix[i][j],matrix[n-1-i][j]);
			}

		}
	}
};

/*二分查找*/
class BinarySearch {
public:
	int solution(vector<int>& nums,int target) {
		int left = -1; 
		int right = nums.size();
		while (left!=right)
		{
			int middle = left + (right-left) / 2;
			if (target<=middle)
			{
				right = middle;
			}
			else
			{
				left = middle;
			}
		}
		return right;
	}
};









/**********************************************************************/


/*********************链表结构*******************************************/


//判断是否是回文字符串，去除非字母数字
class ValidPalindrome {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left<right) {
			if (!::isalnum(*left))
			{
				++left;
			}
			else if (!::isalnum(*right))
			{
				--right;
			}
			else if (*right != *left)
			{
				return false;
			}
			else
			{
				left++;
				right--;
			}
		}
		return true;
	}
};

/*链表：AddTwoNumbers*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class AddTwoNumbers {
public:	
	ListNode *solution(ListNode *l1,ListNode *l2) {
		ListNode preHead(0);
		ListNode *p = &preHead;
		int extra = 0;
		while (l1||l2||extra)
		{
			int sum = (l1?l1->val:0) + (l2?l2->val:0) + extra;
			extra = sum / 10;
			p->next = new ListNode(sum%10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return preHead.next;
	}
};
/************************************************************/
//链表反转I:
class ReverseLinkedList {

public:
	//使用中间变量，反转
	ListNode * solution01(ListNode *head) {
		ListNode *temp = NULL;
		ListNode *nextNode = NULL;
		while (head) {
			nextNode = head->next;
			head->next = temp;
			temp = head;
			head = nextNode;
		}
		return temp;
	}
	//使用头插法
	ListNode *solution03(ListNode *head){
		ListNode *cur= NULL;
		ListNode *tmp = NULL;
		cur->next = head->next;
		head->next = NULL;
		while (cur!=NULL)
		{
			tmp = cur->next;
			cur->next = head->next;
			head->next = cur;
			cur = tmp;
		}
		return head;
	}
	//使用递归
	ListNode *solution02(ListNode *head) {
		if (head==NULL)
		{
			return NULL;
		}
		if (head->next == NULL) {
			return head;
		}
		ListNode *p = head->next;
		ListNode *n = solution02(p);
		head->next = NULL;
		p->next = head;
		return n;
	}

	//ListNode *solution03(ListNode *head) {

	//}
};


/************************************************************/
//链表反转II:
class ReverseLinkedListII {
public:
	ListNode *solution(ListNode *head,int m,int n){
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev = &dummy;
		for (size_t i = 0; i < m-1; i++)
		{
			prev = prev->next;
		}
		ListNode * const head2 = prev;
		prev = head2->next;
		ListNode *cur = prev->next;
		for (size_t i = m; i < n; i++)
		{
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = prev->next;
		}
		return dummy.next;
	}
};

/************************************************************/


//Rotate List
class RotateList {
public:
	ListNode * solution(ListNode *head,int k) {
		if (head==NULL||k==0)
		{
			return head;
		}
		int len = 1;
		ListNode *p = head;
		while (p->next)
		{
			len++;
			p = p->next;
		}
		k = k % len;
		p->next = head;//首尾相连
		for (size_t i = 0; i < k; i++)
		{
			p = p->next;
		}
		head = p->next;//在合适的位置断开
		p->next = NULL;
		return head;
	}
};
/************************************************************/

//Remove Nth Node From End of List
class RemoveNthNode {
public:
	ListNode * solution1(ListNode *head,int n) {
		if (head == NULL)
		{
			return head;
		}
		ListNode *p = head;
		int len = 1;
		while (p->next)
		{
			len++;
			p = p->next;
		}
		if (len == n)
		{
			return head->next;
		}
		p = head;
		for (int i = 0; i<len - n - 1; i++)
		{
			p = p->next;
		}
		ListNode *tmp = p->next;
		p->next = tmp->next;
		delete tmp;
		return head;
	}
	ListNode * solution2(ListNode*head,int n) {
	
		ListNode dummy = ListNode(-1);
		dummy.next = head;
		ListNode *p = &dummy;
		ListNode *q = &dummy;
		for (size_t i = 0; i < n; i++)
		{
			p = p->next;
		}
		while (p->next)
		{
			q = q->next;
			p = p->next;
		}
		ListNode *tmp = q->next;;
		q->next = tmp->next;
		delete tmp;
		return dummy.next;
	}
};
/************************************************************/

/***********************动态规划题目*************************/
//求最长连续增长子序列的长度
//如何返回最长连续增长子序列？
class  LongestContinuousIncreasingSubsequence {
public:
	int solution(vector<int> &nums) {
		int count = 0;
		int result = 0;
		for (size_t  i = 0; i <nums.size(); i++)
		{
			if (i==0||nums[i-1]<nums[i])
			{
				count++;
				result = max(result,count);
			}
		}
		return result;
	}
};
/***************************************************************/
// Swap Nodes in Pairs
class SwapNodesInPairs {
public:
	ListNode * swapPairs01(ListNode *head) {
		if (head==NULL||(head->next)==NULL)
		{
			return head;
		}
		ListNode dummy = ListNode(-1);
		dummy.next = head;
		for (ListNode *prev=&dummy,*cur=prev->next,*next=cur->next;
			next;
			prev=cur,cur=next,next=cur?cur->next:NULL)
		{
			prev->next = next;
			cur->next = next->next;
			next->next = cur;			
		}
		return dummy.next;
	}
	ListNode *swapPairs02(ListNode *head){
		if (head==NULL||(head->next)==NULL)
		{
			return head;
		}
		ListNode *cur = head;
		ListNode *next = cur->next;
		cur->next = swapPairs02(next->next);
		next->next = cur;
		return next;
	}

};


/****************************************************************/

/************Hash Table**************/
class FourSum {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int>  abSum;
		for (auto a : A) {
			for (auto b : B) {
				for (auto c : C) {
					++abSum[a + b + c];
				}

			}
		}
		int count = 0;
		for (auto d : D) {
			auto it = abSum.find(0 - d);
			if (it != abSum.end()) {
				count += it->second;
			}
		}
		return count;
	}
};
/****************************************************************/

/***************Preorder Traversal********************/



/****************线段包含******************************/
typedef struct Segment
{
	int start;
	int end;
}SegInfo;
bool cmp(const Segment &seg1, const Segment &seg2) {

	if (seg1.start<seg2.start)
	{
		return true;
	}
	else if (seg1.start>seg2.start)
	{
		return false;
	}
	else
	{
		return seg1.end < seg2.end;
	}
}
int merge_arr(vector<SegInfo> &seg1, vector<SegInfo> &seg2) {

	int n = seg1.size();
	sort(seg1.begin(), seg1.end(), cmp);
	seg2.push_back(seg1[0]);
	SegInfo test = seg1[0];
	int start = seg1[0].start;
	int end = seg1[0].end;
	int current = 0;

	for (int i = 1; i < seg1.size(); i++)
	{
		if (seg1[i].start>seg2[current].end)
		{
			seg2.push_back(seg1[i]);
			current++;
		}
		else if (seg1[i].start&&seg1[i].end>seg2[current].end) {
			seg2[current].end = seg1[i].end;
		}
	}
	return 0;

}
bool is_contain(const vector<SegInfo>seg1,const vector<SegInfo> seg2) {
	int count = 0;
	for (auto seg_2:seg2)
	{
		for (auto seg_1:seg1)
		{
			if (seg_2.start>=seg_1.start&&seg_2.end<=seg_1.end)
			{
				count++;
			}
		}
	}
	if (seg2.size()==count)
	{
		return true;
	}
	return false;
}


/*********** 二叉树的遍历 *****************/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};

};
/*建立一棵二叉树*/
void createTree(TreeNode *&root)
{
	int x;
	cin >> x;
	if (x==-1) 
	{
		cout << "create end!" << endl;
		root = nullptr;
		return;
	}
	cout << "creatint..." << endl;
	root = new TreeNode(x);
	createTree(root->left);
	createTree(root->right);
}
/****** 递归实现遍历 ********/
//先序遍历
void preOrder(TreeNode *root) 
{
	if (root==nullptr)
	{
		return;
	}
	cout << root->val << endl;
	preOrder(root->left);
	preOrder(root->right);
}
//中序遍历
void inOrder(TreeNode *root) 
{
	if (root==nullptr)
	{
		return;
	}
	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}
//后序遍历
void postOrder(TreeNode *root) 
{
	if (root==nullptr)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << endl;
}
/****** 非递归实现遍历 *******/
void preOrderF(TreeNode *root)
{
	if (root==nullptr)
	{
		return;
	}
	TreeNode *p = nullptr;
	stack<TreeNode *>s;
	s.push(root);
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		cout << p->val << endl;
		if (p->right)
		{
			s.push(p->right);
		}
		if (p->left) 
		{
			s.push(p->left);
		}
	}

}
//中序遍历
void inOrderF(TreeNode *root)
{
	if (root==nullptr)
	{
		return;
	}
	TreeNode *p = root;
	stack<TreeNode *> s;
	while (p||!s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->val << endl;
			p = p->right;
		}
	}



}
//后序遍历
void postOrderF(TreeNode *root)
{
	if (root==nullptr)
	{
		return;
	}
	TreeNode *p = nullptr;
	vector<int>result;
	stack<TreeNode *>s;
	s.push(root);
	while (s.empty())
	{
		p = s.top();
		s.pop();
		result.insert(result.begin(),p->val);
		if (p->left)
		{
			s.push(p->left);
		}
		if (p->right)
		{
			s.push(p->right);
		}
	}
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
}

#endif