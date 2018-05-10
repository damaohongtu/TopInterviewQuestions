#include "stdafx.h"
#include <cstdio>
#include "BinaryTreeNode.h"
#include<deque>
#include<stack>
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is nullptr.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
//树的广度优先算法
void printFromTopToBottom(BinaryTreeNode* pTreeNode) {
	if (!pTreeNode) {
		return;
	}
	std::deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pTreeNode);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d ",pNode->m_nValue);
		if (pNode->m_pLeft)
		{
			dequeTreeNode.push_back(pNode->m_pLeft);
		}
		if (pNode->m_pRight)
		{
			dequeTreeNode.push_back(pNode->m_pRight);
		}
	}
}
//树的广度优先遍历算法，按照行来进行打印
void printFromTopToBottomByLevel(BinaryTreeNode* pTreeNode) {
	if (pTreeNode==nullptr)
	{
		return;
	}
	std::deque<BinaryTreeNode *>dequeTreeNode;
	dequeTreeNode.push_back(pTreeNode);
	int nextLevel = 0;
	int toPrint = 1;
	while (dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d ",pNode->m_nValue);
		toPrint--;
		if (pNode->m_pLeft)
		{
			dequeTreeNode.push_back(pNode->m_pLeft);
			nextLevel++;
		}
		if (pNode->m_pRight)
		{
			dequeTreeNode.push_back(pNode->m_pRight);
			nextLevel++;
		}
		if (toPrint==0)
		{
			printf("\n");
			toPrint = nextLevel; 
			nextLevel = 0;
		}
	}
}
//树的广度优先遍历算法，按照zigzag行来进行打印
void printFromTopToBootomZigzag(BinaryTreeNode *pTreeNode) {
	if (pTreeNode==nullptr) {
		return;
	}
	//定义stack数组，分别用来保存奇数行和偶数行
	std::stack<BinaryTreeNode *>level[2];
	int current = 0;//当前正在遍历的行
	int next = 1;//将要打印的下一行
	level[current].push(pTreeNode);
	while (!level[current].empty()||!level[next].empty())
	{
		BinaryTreeNode *pNode = level[current].top();
		level[current].pop();
		printf("%d ", pNode->m_nValue);
		if (current==0) {
			//以下针对于偶数列，压栈的顺序是先左后右，出栈的时候是先右后左
			if (pNode->m_pLeft) {
				level[next].push(pNode->m_pLeft);
			}
			if (pNode->m_pRight) {
				level[next].push(pNode->m_pRight);
			}
		}
		if (current==1)
		{
			//以下针对奇数行，压栈先右后左，出栈先左后右
			if (pNode->m_pRight) {
				level[next].push(pNode->m_pRight);
			}
			if (pNode->m_pLeft) {
				level[next].push(pNode->m_pLeft);
			}
		}
		//每完成一次迭代，进行一次交换
		if (level[current].empty())
		{
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}

	}
}
bool isSequenceOfBST(int sequence[], int length) {
	if (sequence==nullptr||length==0) {
		return false;
	}
	int root = sequence[length-1];
	
	/*
	边界：0,1,2,3,...i-1|,i,i+1,...length-2|,length-1
	以上：i:第一个右子树，length-2:最后一个右子树节点，length-1:root节点
	长度：左子树：(i-1)-(0)+1=i      右子树：(length-2)-(i)+1=length-1-i
	*/
	int i = 0;
	for (; i < length-1; i++)
	{
		if (sequence[i]>root) {
			break;
		}
	}
	int j = i;
	for (; j < length-1; j++)
	{
		if (sequence[j]<root) {
			return false;
		}
	}
	//左自树
	bool left = true;
	if (i!=0) {
		isSequenceOfBST(sequence,i);
	}
	//右子树
	if (i<(length-1))
	{
		isSequenceOfBST(sequence + i,length-i-1);
	}
	bool right = true;
	return left && right;
}