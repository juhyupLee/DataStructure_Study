#pragma once
typedef int BTData;

typedef struct _bTreeNode
{

	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;


}BTreeNode;

BTreeNode* MakeBtreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData Data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
