// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Extern.h"
#include "ArrayList.h"
using namespace std;

int main()
{

	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	cout << "현재 데이터의 갯수:" << LCount(&list) << endl;
	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

	}
	if (LFirst(&list, &data))
	{
		if (data %2== 0)
		{
			LRemove(&list);

		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
			{
				LRemove(&list);
			}
		}
	}
	cout << "현재 남아있는 데이터의수:" << LCount(&list) << endl;


	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

	}
	


	

}
