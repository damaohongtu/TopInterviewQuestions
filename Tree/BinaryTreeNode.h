#pragma once
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
//�������Ļ�������
BinaryTreeNode* createBinaryTreeNode(int value);
void connectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight);
void printTreeNode(const BinaryTreeNode* pNode);
void printTree(const BinaryTreeNode *pRoot);
void destroyTree(BinaryTreeNode *pRoot);

//���Ĺ����������
void printFromTopToBottom(BinaryTreeNode* pTreeNode);