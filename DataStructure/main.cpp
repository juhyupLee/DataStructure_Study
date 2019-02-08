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
#include "ArrayQueue.h"

#define CUS_COME_TERM 15
#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

using namespace std;
int main()
{

	int makeProc = 0;
	int CheOrder = 0, BulOrder = 0, DubOrder = 0;
	int Sec;


	Queue Que;

	QueueInit(&Que);
	srand((unsigned int)time(NULL));

	for (Sec = 0; Sec < 3600; ++Sec)
	{
		if (Sec%CUS_COME_TERM == 0)//15초 //고객주문이들어오는시간
		{
			switch (rand() % 3)// 버거 셋중에 랜덤으로
			{
			case CHE_BUR:
				Enqueue(&Que, CHE_TERM);
				CheOrder++;
				break;
			case BUL_BUR:
				Enqueue(&Que, BUL_TERM);
				BulOrder++;
				break;
			case DUB_BUR:
				Enqueue(&Que, DUB_TERM);
				DubOrder++;
				break;

			}
		}


			if (makeProc <= 0 && QIsEmpty(&Que))
			{
				makeProc = Dequeue(&Que);

			}

			makeProc--;

	}
	

	cout << "Simulation Report" << endl;
	cout << "Cheese Burger : " << CheOrder << endl;
	cout << "Bulgogi Burger : " << BulOrder << endl;
	cout << "Double Burger : " << DubOrder << endl;
	cout << "Waiting Room" << QUE_LEN << endl;


}
