// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
//#include "ArrayList.h"
#include "DLinkedList.h"
using namespace std;

int main()
{
	List list;
	LData Data = 0;

	ListInit(&list);
	
	SetSortRule(&list,Compare);


		SInsert(&list, (LData)1);
		SInsert(&list, (LData)3);
		SInsert(&list, (LData)5);
		SInsert(&list, (LData)2);
		SInsert(&list, (LData)4);

	if (LFirst(&list, &Data))
	{
		cout << Data << " ";

	}
	while (LNext(&list, &Data))
	{
		cout << Data << " ";
	}

	cout << endl;
	//if (LFirst(&list, &Data))
	//{
	//	if (Data % 2 == 1)
	//	{
	//		LRemove(&list);
	//	}
	//	while (LNext(&list, &Data))
	//	{
	//		if (Data % 2 == 1)
	//		{
	//			LRemove(&list);
	//		}
	//	}

	//}
	//if (LFirst(&list, &Data))
	//{
	//	cout << Data << " ";

	//}
	//while (LNext(&list, &Data))
	//{
	//	cout << Data << " ";
	//}

}
