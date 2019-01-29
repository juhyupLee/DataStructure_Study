// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//#include "ArrayList.h"
//#include "DLinkedList.h"
//#include "CLinkedList.h"
//#include "DoubleLinkedList.h"
//#include "DoubledLinkedList2.h"
//#include "ArrayStack.h"
//#include "LinkedStack.h"
#include "CLinkedList Apply Stack.h"
using namespace std;

int main()
{
	//Test Source Tree Test
	CList_Sol Stack;
	Data data = 0;

	StackInit(&Stack);
	Push(&Stack, 10);
	Push(&Stack, 20);
	Push(&Stack, 30);
	Push(&Stack, 40);
	Push(&Stack, 50);
	
	while (IsEmpty(&Stack))
	{
		cout << Pop(&Stack) << endl;;
	}


}
