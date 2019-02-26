#include "BinaryTree.h"
#include <iostream>
#include <string.h>
#include "LinkedStack.h"
using namespace std;

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

BTreeNode * GetRightSubTree(BTreeNode * bt)
{

	return bt->right;
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

void Travel(BTreeNode * bt)
{
	if (bt == nullptr)
	{
		return;
	}
	Travel(GetLeftSubTree(bt));
	cout << bt->data << endl;
	Travel(GetRightSubTree(bt));

}
bool IsDigit(char ch)
{
	if (48 <= ch && ch <= 57)				//ASCII '0'~'9'
	{
		return true;
	}
	else
	{
		return false;
	}
}
BTreeNode * MakeExpTree(const char * pstr)
{
	int len = strlen(pstr);
	LinkedStack stack;
	StackInit(&stack);

	for (int i = 0; i < len; ++i)
	{
		BTreeNode* Node = MakeBtreeNode();//일단 노드를 만들고. 노드의 데이터는.......int? char?
		
		if (IsDigit(pstr[i])) // 숫자일경우
		{
			//스택에넣어야지
			SetData(Node, pstr[i] - '0');
		}
		else//연산자일경우
		{
			SetData(Node, pstr[i]);
			BTreeNode* Num2 = Pop(&stack);
			BTreeNode* Num1 = Pop(&stack);
			MakeLeftSubTree(Node, Num1);
			MakeRightSubTree(Node, Num2);
			// 왼쪽오른쪽 연결 해주고	
		}
		Push(&stack, Node);

	}

	return Pop(&stack);

}

int UltimateCal(BTreeNode* btnode)
{

	if (nullptr == btnode->left && nullptr == btnode->right)
	{
		return GetData(btnode);
	}

	int Op1 = UltimateCal(GetLeftSubTree(btnode));
	int Op2 = UltimateCal(GetRightSubTree(btnode));

	switch (btnode->data)
	{

		case '+':
			return Op1 + Op2;
			break;

		case '-':
			return Op1 + Op2;
			break;

		case '*':
			return Op1 * Op2;
			break;

		case '/':
			return Op1 / Op2;
			break;

		default:
			return 0;
			break;

	}

}

BTreeNode * RemovdeLeftSubTreE(BTreeNode * bt)
{
	if (nullptr == bt->left)
		return nullptr;
	else
	{
		BTreeNode* DelNode = bt->left;
		bt->left = nullptr;
		return DelNode;
	}
}

BTreeNode * RemovdeRightSubTree(BTreeNode * bt)
{
	if (nullptr == bt->right)
		return nullptr;
	else
	{
		BTreeNode* DelNode = bt->right;
		bt->left = nullptr;
		return DelNode;
	}
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}



