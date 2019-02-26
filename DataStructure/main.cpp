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
//#include "BinaryTree.h"
//#include "SimpleHeap.h"
//#include "sort.h"
//#include "UsefulHeap.h"
//#include "MergeSort.h"
//#include "QuickSort.h"
#include "BinarySeachTree.h"

using namespace std;

//using namespace UsefulHeap;
int main()
{
	BTreeNode* pRootNode = MakeBtreeNode();
	BSTMakeAndInit(&pRootNode);

	BSTInsert(&pRootNode, 10);
	BSTInsert(&pRootNode, 20);
	BSTInsert(&pRootNode, 30);
	BSTInsert(&pRootNode, 40);


	cout << BSTRemove(&pRootNode,20)->data<< endl;


}
