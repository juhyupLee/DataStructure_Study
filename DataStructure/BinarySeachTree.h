#pragma once
#include "BinaryTree.h"

typedef BTData BSTData;

//BST�� ���� �� �ʱ�ȭ;
void BSTMakeAndInit(BTreeNode** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

//BST�� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

//BST�� ������� ������Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// Ʈ������ ��带 �����ϤǤ� ���ŵ� ����� �ּҰ��� ��ȯ�Ѵ�.

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

//����Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�
void BSTShowAll(BTreeNode* bst);




