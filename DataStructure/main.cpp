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
#include "SimpleHeap.h"


using namespace std;

int main()
{
	Heap heap;

	HeapInit(&heap);
	HInsert(&heap, 1,1);
	HInsert(&heap, 3, 3);
	HInsert(&heap, 5, 5);
	HInsert(&heap, 7, 7);
	HInsert(&heap, 2, 2);
	HInsert(&heap, 9, 9);
	HInsert(&heap, 11, 11);
	HInsert(&heap, 13, 13);
	
	while (!HIsEmpty(&heap))
	{
		cout << HDelete(&heap) << endl;
	}

}
