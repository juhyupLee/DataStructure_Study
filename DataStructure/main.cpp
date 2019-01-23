// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
//#include "ArrayList.h"
//#include "DLinkedList.h"
#include "CLinkedList.h"
using namespace std;

int main()
{
	//Test Source Tree Test
	CList list;
	Data Data = 0;

	ListInit(&list);
	LInsert(&list,	1);
	LInsert(&list,  2);
	LInsert(&list,  3);
	LInsert(&list, 4);

	if (LFirst(&list, &Data))
	{
		cout << Data << endl;

		while (LNext(&list, &Data))
		{
			cout << Data << endl;
		}
	}
		

	cout << endl;
	if (LFirst(&list, &Data))
	{
		if (Data % 2 == 0)
		{
			LRemove(&list);
		}
		while (LNext(&list, &Data))
		{
			if (Data % 2 == 0)
			{
				LRemove(&list);
			}
		}

	}
	if (LFirst(&list, &Data))
	{
		cout << Data << " ";

	}
	while (LNext(&list, &Data))
	{
		cout << Data << " ";
	}

}
