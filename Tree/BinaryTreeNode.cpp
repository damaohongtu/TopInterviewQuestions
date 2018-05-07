#include"BinaryTreeNode.h"
#include<deque>
#include<iostream>
using namespace std;
BinaryTreeNode* createBinaryTreeNode(int value) {

}
void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	
}
void printTreeNode(const BinaryTreeNode* pNode) {
	
}
void printTree(const BinaryTreeNode *pRoot) {
	
}
void destroyTree(BinaryTreeNode *pRoot) {
	
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
		cout << pNode->value << endl;
		if (pNode->left)
		{
			dequeTreeNode.push_back(pNode->left);
		}
		if (pNode->right)
		{
			dequeTreeNode.push_back(pNode->right);
		}
	}
}