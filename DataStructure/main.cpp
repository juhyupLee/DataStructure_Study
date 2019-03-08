// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
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
//#include "BinarySeachTree.h"

#include "HashTable.h"
using namespace std;

//using namespace UsefulHeap;
#include <map>


int MyHashFunc(int k)
{
	return k % 100;

}

int main()
{
	

	UserData Ju("LeeJu", 920520);
	UserData Yu("LeeYu", 921218);

	HashTable hi(MyHashFunc);

	hi.insert(Ju.GetRegister(), Ju);
	hi.insert(Yu.GetRegister(), Yu);

	UserData* Search = hi.search(920520);

	cout << Search->GetRegister() << endl;

}
