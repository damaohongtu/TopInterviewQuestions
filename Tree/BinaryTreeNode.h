#pragma once
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
//二叉树的基本操作
BinaryTreeNode* createBinaryTreeNode(int value);
void connectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight);
void printTreeNode(const BinaryTreeNode* pNode);
void printTree(const BinaryTreeNode *pRoot);
void destroyTree(BinaryTreeNode *pRoot);

//树的广度优先搜索
void printFromTopToBottom(BinaryTreeNode* pTreeNode);