#include "BinarySeachTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	(*pRoot)->left = nullptr;
	(*pRoot)->right = nullptr;
	SetData(*pRoot, -1);


}

BSTData BSTGetNodeData(BTreeNode * bst)
{

	return bst->data;

}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode* pCurrentNode = *pRoot;

	if (GetData(pCurrentNode) < 0)// ���ԵǴ� ��尡 ù����϶�
	{
		SetData(pCurrentNode, data);
		return;
	}

	BTreeNode* pPrevNode = nullptr;
	BTreeNode* pNewNode = MakeBtreeNode();
	SetData(pNewNode, data);
	bool IsRight = true;

	while (pCurrentNode != nullptr)
	{
		if (GetData(pCurrentNode) > data)
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->left;
			IsRight = false;

		}
		else
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->right;
			IsRight = true;
		}
	}
	if (IsRight)
	{
		MakeRightSubTree(pPrevNode, pNewNode);
	}
	else
	{
		MakeLeftSubTree(pPrevNode, pNewNode);
	}
}

//�������ִٰ� ������.

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode* pCurrentNode = bst;

	while (pCurrentNode != nullptr)
	{
		if (GetData(pCurrentNode) == target)
		{
			break;
		}
		else
		{
			if (GetData(pCurrentNode) < target)
			{
				pCurrentNode = pCurrentNode->right;
			}
			else
			{
				pCurrentNode = pCurrentNode->left;
			}
		}

	}

	return pCurrentNode;
}
