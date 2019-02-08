// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include "ArrayList.h"
//#include "DLinkedList.h"
//#include "CLinkedList.h"
//#include "DoubleLinkedList.h"
//#include "DoubledLinkedList2.h"
//#include "ArrayStack.h"
//#include "LinkedStack.h"
//#include "CLinkedList Apply Stack.h"
//#include "Calculator.h"
//#include "ArrayQueue.h"
#include "BinaryTree.h"


using namespace std;
int main()
{
	BTreeNode* pNodeA = MakeBtreeNode();
	BTreeNode* pNodeB = MakeBtreeNode();
	BTreeNode* pNodeC = MakeBtreeNode();
	BTreeNode* pNodeD = MakeBtreeNode();


	SetData(pNodeA, 10);
	SetData(pNodeB, 20);
	SetData(pNodeC, 30);
	SetData(pNodeD, 40);

	
	MakeLeftSubTree(pNodeA, pNodeB);
	MakeRightSubTree(pNodeA, pNodeC);
	MakeLeftSubTree(pNodeB, pNodeD);

	cout << GetData(pNodeA) << endl;
	cout << GetData(GetLeftSubTree(pNodeA));
	cout << GetData(GetLeftSubTree(GetLeftSubTree(pNodeA)));

	

}
