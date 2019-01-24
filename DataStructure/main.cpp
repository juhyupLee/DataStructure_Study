// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//#include "ArrayList.h"
//#include "DLinkedList.h"
//#include "CLinkedList.h"
//#include "DoubleLinkedList.h"
#include "DoubledLinkedList2.h"

using namespace std;

int main()
{
	//Test Source Tree Test
	DBList2 list;                    
	Data Data = 0;

	ListInit(&list);
	LInsert(&list,	1);
	LInsert(&list,  2);
	LInsert(&list,  3);
	LInsert(&list, 4);

	cout << "총리스트" << endl;
	if (LFirst(&list, &Data))
	{
		cout << Data << endl;

		while (LNext(&list, &Data))
		{
			cout << Data << endl;
		}
		while (LPrevious(&list, &Data))
		{
			cout << Data << endl;
		}
	}

	
	if (LFirst(&list, &Data))
	{
		if (1 == Data % 2)
		{
			LRemove(&list);
		}
		while (LNext(&list, &Data))
		{
			if (1 == Data % 2)
			{
				LRemove(&list);
			}
		}
	}

	cout << "삭제 후리스트 " << endl;
	if (LFirst(&list, &Data))
	{
		cout << Data << endl;

		while (LNext(&list, &Data))
		{
			cout << Data << endl;
		}

	}


		
}
