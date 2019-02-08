#include "BinaryTree.h"

BTreeNode * MakeBtreeNode(void)
{

	BTreeNode* pNewNode = new BTreeNode;
	pNewNode->left = nullptr;
	pNewNode->right = nullptr;

	return pNewNode;
}

BTData GetData(BTreeNode * bt)
{
	
	return bt->data;

}

void SetData(BTreeNode * bt, BTData Data)
{
	bt->data = Data;

}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	
	return bt->left;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{

	if (main->left != nullptr)
	{
		delete main->left;

	}
	main->left = sub;

}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{

	if (main->right != nullptr)
	{
		delete main->right;
	}
	main->right = sub;

}
