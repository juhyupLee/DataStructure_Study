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
#include "QuickSort.h"
using namespace std;

//using namespace UsefulHeap;
int main()
{
	//int Arr[8] = { 2,1,4,3,6,5,7,8 };
	int Arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	
	int n = sizeof(Arr) / sizeof(int);

	QuickSort(Arr, 0, n-1);

	/*for (int i = 0;i < 8;++i)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;*/
}
