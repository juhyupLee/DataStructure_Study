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
	if (48 <= ch && ch <= 57)
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
		BTreeNode* Node = MakeBtreeNode();//�ϴ� ��带 �����. ����� �����ʹ�.......int? char?
		

		if (IsDigit(pstr[i])) // �����ϰ��
		{
			//���ÿ��־����
			SetData(Node, pstr[i] - '0');
			Push(&stack, Node);
		}
		else//�������ϰ��
		{
			SetData(Node, pstr[i]);
			BTreeNode* Num2 = Pop(&stack);
			BTreeNode* Num1 = Pop(&stack);
			MakeLeftSubTree(Node, Num1);
			MakeRightSubTree(Node, Num2);
			// ���ʿ����� ���� ���ְ�
			Push(&stack, Node);
		}

	}

	return Pop(&stack);
}
