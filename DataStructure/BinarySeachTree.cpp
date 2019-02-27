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

	if (GetData(pCurrentNode) < 0)// 삽입되는 노드가 첫노드일때
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

//무조건있다고 가정함.

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
	BTreeNode* VirtualRoot = MakeBtreeNode();
	MakeRightSubTree(VirtualRoot, *pRoot);// Virtual root의 오른쪽 자식으로 진짜 루트노드를 드림

	BTreeNode* CurNode = *pRoot;
	BTreeNode* PNode = VirtualRoot;
	bool IsRight = true;

	while (CurNode != nullptr)
	{
		if (GetData(CurNode) == target)
		{
			break;
		}
		else if (GetData(CurNode) > target)
		{
			//그러면 왼쪽 트리로
			IsRight = false;
			PNode = CurNode;
			CurNode = CurNode->left;
		}
		else if (GetData(CurNode) < target)
		{
			//그러면 오른쪽 트리로
			IsRight = true;
			PNode = CurNode;
			CurNode = CurNode->right;
		}
	}

	if (CurNode == nullptr)
	{
		return nullptr; // 탐색결과 없음
	}

	//그런데 타겟이있는경우
	//그 타겟이 단일노드인경우
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
	else if (CurNode->left == nullptr || CurNode->right == nullptr)//단일노드가 한개인경우
	{
		if (CurNode->left == nullptr)
		{
			ChangeRightSubTree(PNode, CurNode->right);
		}
		else
		{
			ChangeLeftSubTree(PNode, CurNode->left);
		}
	}
	else //자식노드가 2개이상인경우
	{
		//대체노드
		BTreeNode* ReplaceNode = CurNode->right;
		//대체노드 부모

		BTreeNode* ReplaceParent = CurNode->right;
		while (GetLeftSubTree(ReplaceNode) !=nullptr)
		{
			ReplaceParent = ReplaceNode;
			ReplaceNode = ReplaceNode->left;
		}
		// 삭제할 노드에 대체노드 데이터 집어넣기
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

	if (VirtualRoot->right != (*pRoot)) // Virtual Root의 오른쪽 자식이 루트노드가아니라면
	{
		*pRoot = VirtualRoot->right;
	}

	//Target에맞는  노드가없는경우

	return CurNode;
}

void BSTShowAll(BTreeNode * bst)
{
}
