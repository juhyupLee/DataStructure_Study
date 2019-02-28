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
#include ""
using namespace std;

//using namespace UsefulHeap;



typedef struct _empInfo
{
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;
}

int main()
{
	EmpInfo empInfoArr[1000];

	EmpInfo emp1 = { 20120003, 42 };
	EmpInfo emp2 = { 20130012, 33 };
	EmpInfo emp3 = { 20170049, 27 };
	
	EmpInfo r1, r2, r3;

	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	r1 = empInfoArr[GetHashValue(20120003)];
	r2 = empInfoArr[GetHashValue(20130012)];
	r3 = empInfoArr[GetHashValue(20170049)];


	printf("사번 %d,나이 %d\n", r1.empNum, r1.age);
	printf("사번 %d,나이 %d\n", r2.empNum, r2.age);
	printf("사번 %d,나이 %d\n", r3.empNum, r3.age);
	return 0;


}
