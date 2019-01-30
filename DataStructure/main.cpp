// DataStructure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//#include "ArrayList.h"
//#include "DLinkedList.h"
//#include "CLinkedList.h"
//#include "DoubleLinkedList.h"
//#include "DoubledLinkedList2.h"
//#include "ArrayStack.h"
#include "LinkedStack.h"
//#include "CLinkedList Apply Stack.h"
using namespace std;
#define SIZE 100
int main()
{


	char Input[] = "(1+2*3)/4*8*2*10";
	char Postfix[SIZE] = "";
	LinkedStack OperStack;

	StackInit(&OperStack);
	int Oper1 = 0;
	int Oper2 = 0;
	int CurIndex = 0;

	int InputSize = sizeof(Input) / sizeof(char);
	
	for (int i = 0;i < InputSize;++i)
	{
		if ('(' == Input[i])
			Oper1 = i;
		if (')' == Input[i])
			Oper2 = i;
	}

	if (Oper1+Oper2 == 0)
	{

	}
	else
	{
		int PostfixInx = 0;
		for (CurIndex = Oper1 + 1;CurIndex <= Oper2; ++CurIndex)
		{
			if (48 <= Input[CurIndex] && Input[CurIndex] <= 57)//숫자일때
			{
				Postfix[PostfixInx] = Input[CurIndex];
				++PostfixInx;
			}
			else//연산자일때
			{
				if (1==IsEmpty(&OperStack))
				{
					Push(&OperStack, Input[CurIndex]);
				}
				else
				{
					if (Peep(&OperStack) == '*' || Peep(&OperStack) == '/')
					{
						if (Input[CurIndex] == '+' || Input[CurIndex] == '-')
						{
							while (0==IsEmpty(&OperStack))
							{
								Postfix[PostfixInx] = Pop(&OperStack);
								++PostfixInx;
							}
							Push(&OperStack, Input[CurIndex]);
						}
					}
					else
					{
						Push(&OperStack, Input[CurIndex]);

					}
				}
			}

		}
		while (0==IsEmpty(&OperStack))
		{
			Postfix[PostfixInx] = Pop(&OperStack);
			++PostfixInx;
		}

		//대괄호 연산 종료후
		for (CurIndex = Oper2 + 1; CurIndex < InputSize-1; CurIndex++)
		{
			if (48 <= Input[CurIndex] && Input[CurIndex] <= 57)//숫자일때
			{
				Postfix[PostfixInx] = Input[CurIndex];
				++PostfixInx;
			}
			else//연산자일때
			{
				if (1 == IsEmpty(&OperStack))
				{
					Push(&OperStack, Input[CurIndex]);
				}
				else
				{
					if (Peep(&OperStack) == '*' || Peep(&OperStack) == '/')
					{
						if (Input[CurIndex] == '+' || Input[CurIndex] == '-')
						{
							while (IsEmpty(&OperStack))
							{
								Postfix[PostfixInx] = Pop(&OperStack);
								++PostfixInx;
							}
							Push(&OperStack, Input[CurIndex]);
						}
						else
						{
							Push(&OperStack, Input[CurIndex]);
						}
					}
					else
					{
						Push(&OperStack, Input[CurIndex]);

					}
				}
			}

		
		}

		while (0 == IsEmpty(&OperStack))
		{
			Postfix[PostfixInx] = Pop(&OperStack);
			++PostfixInx;
		}

	}
	cout << Postfix << endl;

}
