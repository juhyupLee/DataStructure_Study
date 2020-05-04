// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
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
#include "Graph.h"
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
	std::vector<const char*> vTemp;
	vTemp.push_back("A");
	vTemp.push_back("B");
	vTemp.push_back("C");
	vTemp.push_back("D");
	vTemp.push_back("E");
	Graph graph(vTemp);

	graph.AddEdge("A", "B");
	graph.AddEdge("A", "C");
	graph.AddEdge("A", "D");
	graph.AddEdge("A", "E");
	graph.AddEdge("B", "A");

	graph.ShowGraphEdgeInfo();

}
