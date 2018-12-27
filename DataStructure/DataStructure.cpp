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
	list_Push_Reverse(1);
	list_Push_Reverse(2);
	list_Push_Reverse(3);
	list_Push_Reverse(4);
	list_Push_Reverse(5);
	list_Push_Reverse(6);

	list_Delete();

}
