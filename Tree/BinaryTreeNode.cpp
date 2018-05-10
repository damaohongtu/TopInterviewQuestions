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
//���Ĺ�������㷨
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
//���Ĺ�����ȱ����㷨�������������д�ӡ
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
//���Ĺ�����ȱ����㷨������zigzag�������д�ӡ
void printFromTopToBootomZigzag(BinaryTreeNode *pTreeNode) {
	if (pTreeNode==nullptr) {
		return;
	}
	//����stack���飬�ֱ��������������к�ż����
	std::stack<BinaryTreeNode *>level[2];
	int current = 0;//��ǰ���ڱ�������
	int next = 1;//��Ҫ��ӡ����һ��
	level[current].push(pTreeNode);
	while (!level[current].empty()||!level[next].empty())
	{
		BinaryTreeNode *pNode = level[current].top();
		level[current].pop();
		printf("%d ", pNode->m_nValue);
		if (current==0) {
			//���������ż���У�ѹջ��˳����������ң���ջ��ʱ�������Һ���
			if (pNode->m_pLeft) {
				level[next].push(pNode->m_pLeft);
			}
			if (pNode->m_pRight) {
				level[next].push(pNode->m_pRight);
			}
		}
		if (current==1)
		{
			//������������У�ѹջ���Һ��󣬳�ջ�������
			if (pNode->m_pRight) {
				level[next].push(pNode->m_pRight);
			}
			if (pNode->m_pLeft) {
				level[next].push(pNode->m_pLeft);
			}
		}
		//ÿ���һ�ε���������һ�ν���
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
	�߽磺0,1,2,3,...i-1|,i,i+1,...length-2|,length-1
	���ϣ�i:��һ����������length-2:���һ���������ڵ㣬length-1:root�ڵ�
	���ȣ���������(i-1)-(0)+1=i      ��������(length-2)-(i)+1=length-1-i
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
	//������
	bool left = true;
	if (i!=0) {
		isSequenceOfBST(sequence,i);
	}
	//������
	if (i<(length-1))
	{
		isSequenceOfBST(sequence + i,length-i-1);
	}
	bool right = true;
	return left && right;
}