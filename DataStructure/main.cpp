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
	vTemp.push_back("동수");
	vTemp.push_back("지율");
	vTemp.push_back("민석");
	vTemp.push_back("지민");
	vTemp.push_back("수정");
	vTemp.push_back("정희");
	vTemp.push_back("명석");
	Graph graph(vTemp);

	graph.AddEdge("동수", "지율");
	graph.AddEdge("동수", "지민");
	graph.AddEdge("지율", "민석");
	graph.AddEdge("지민", "민석");
	graph.AddEdge("민석", "수정");
	graph.AddEdge("민석", "정희");
	graph.AddEdge("정희", "수정");
	graph.AddEdge("정희", "명석");


	graph.ShowGraphEdgeInfo();
	graph.DFShowGraphVertex("동수");
	graph.DFShowGraphVertex("수정");

	graph.BFShowGraphVertex("지율");

	return 0;

}
