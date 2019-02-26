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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode* CurNode = *pRoot;
	BTreeNode* PNode = CurNode;
	bool IsRight = true;

	while (CurNode != nullptr)
	{
		if (GetData(CurNode) == target)
		{
			break;
		}
		else if (GetData(CurNode) > target)
		{
			//�׷��� ���� Ʈ����
			IsRight = false;
			PNode = CurNode;
			CurNode = CurNode->left;
		}
		else if (GetData(CurNode) < target)
		{
			//�׷��� ������ Ʈ����
			IsRight = true;
			PNode = CurNode;
			CurNode = CurNode->right;
		}

	}

	if (CurNode == nullptr)
	{
		return nullptr; // Ž����� ����
	}

	//�׷��� Ÿ�����ִ°��
	//�� Ÿ���� ���ϳ���ΰ��
	if (nullptr == CurNode->left && nullptr == CurNode->right)
	{
		if (IsRight)
		{
			return RemovdeRightSubTree(PNode);
		}
		else
		{
			return RemovdeLeftSubTreE(PNode);
		}
	}
	else if ((CurNode->left != nullptr && CurNode->right == nullptr) ||
			 (CurNode->left == nullptr && CurNode->right != nullptr))//���ϳ�尡 �Ѱ��ΰ�� 
	{
		if (CurNode->left == nullptr)
		{
			ChangeLeftSubTree(PNode, CurNode->right);
		}
		else
		{
			ChangeLeftSubTree(PNode, CurNode->left);
		}
	}
	else //�ڽĳ�尡 2���̻��ΰ��
	{
		//�� Ÿ�ٳ�忡�� �����ʿ��� ��������
		BTreeNode* ReplaceNode = CurNode->right;
		BTreeNode* ReplaceParent = CurNode->right;
		while (GetLeftSubTree(ReplaceNode) !=nullptr)
		{
			ReplaceParent = ReplaceNode;
			ReplaceNode = ReplaceNode->left;
		}
		SetData(CurNode, ReplaceParent->data);
		if (GetLeftSubTree(ReplaceParent) == ReplaceNode)
		{
			ChangeLeftSubTree(ReplaceParent, GetRightSubTree(ReplaceNode));
		}
		else
		{
			ChangeRightSubTree(ReplaceParent, GetRightSubTree(ReplaceNode));
		}


	}

	//Target���´�  ��尡���°��

	return CurNode;
}

void BSTShowAll(BTreeNode * bst)
{
}
