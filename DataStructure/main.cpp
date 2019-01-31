// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
//#include "ArrayList.h"
//#include "DLinkedList.h"
//#include "CLinkedList.h"
//#include "DoubleLinkedList.h"
//#include "DoubledLinkedList2.h"
//#include "ArrayStack.h"
//#include "LinkedStack.h"
//#include "CLinkedList Apply Stack.h"
//#include "Calculator.h"
#include "ArrayQueue.h"
using namespace std;
#define SIZE 100
int main()
{
	Queue Que;

	QueueInit(&Que);

	Enqueue(&Que, 10);
	Enqueue(&Que, 20);
	Enqueue(&Que, 30);
	Enqueue(&Que, 40);
	Enqueue(&Que, 50);
	Enqueue(&Que, 60);

	while (!QIsEmpty(&Que))
	{
		cout << Dequeue(&Que) << endl;
	}




}
