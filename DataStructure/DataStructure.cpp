// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "LinkedList.h"
#include "Extern.h"

int main()
{
	Data num = 0;

	list_Init();
	list_Push((Data)10);
	list_Push((Data)20);
	list_Push((Data)30);
	list_Push((Data)40);

	list_Delete();

}
