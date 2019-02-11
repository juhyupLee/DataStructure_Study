//#include "Calculator.h"
//#include "LinkedStack.h"
//#include <stdlib.h>
//
//
//
////(1+2*3)/4
//int OP_Priority(char input)
//{
//	switch (input)
//	{
//	case '+':
//	case '-':
//		return 3;
//
//	case '*':
//	case '/':
//		return 5;
//
//	case '(':
//		return 1;
//	default:
//		return -1;
//	}
//
//}
//int Who_Is_Priority(char input1, char input2)
//{
//	int Priority_Before = OP_Priority(input1);
//	int Priority_After = OP_Priority(input2);
//
//	if (Priority_Before >= Priority_After)
//		return 1;
//	else if (Priority_Before < Priority_After)
//		return 0;
//	else
//		return -1;
//
//
//}
//char * Infix_To_PostFix(const char * input)
//{
//	int len = strlen(input);
//	//Operator 을 담기위한 스택생성
//
//	LinkedStack OperStack;
//	StackInit(&OperStack);
//
//	char* PostFix = new char[len+1] ;
//	//strcpy_s(PostFix,len+1, input);
//	int PostIndex = 0;
//
//	for (int i = 0; i < len+1; ++i)
//	{
//		if (IsDigit(input[i]))
//		{
//			PostFix[PostIndex++] = input[i];
//		}
//		else//숫자가아닌 Operator일때... 
//		{
//			switch (input[i])
//			{
//				case '(':
//					Push(&OperStack, input[i]);
//					break;
//				case '+':
//				case '-':
//				case '*':
//				case '/':
//					if (!IsEmpty(&OperStack) && Who_Is_Priority(Peep(&OperStack), input[i]))
//					{
//						while (!IsEmpty(&OperStack))
//						{
//							if ('(' == Peep(&OperStack))
//								break;
//
//							PostFix[PostIndex++] = Pop(&OperStack);
//						}
//					}
//					Push(&OperStack, input[i]);
//					break;
//
//				case ')':
//					while (!IsEmpty(&OperStack))
//					{
//						char Popchr = Pop(&OperStack);
//						if (Popchr == '(')
//							break;
//						PostFix[PostIndex++] = Popchr;
//					}
//					break;
//
//			}
//		}
//	}
//
//	while (!IsEmpty(&OperStack))
//	{
//		char Popchr = Pop(&OperStack);
//	
//		PostFix[PostIndex++] = Popchr;
//	}
//	PostFix[PostIndex] = '\0';
//
//	return PostFix;
//}
//
//
//int PostFix_To_Result(char * input)
//{
//	char* pPostFix = Infix_To_PostFix(input);
//	
//	int len = strlen(pPostFix);
//	LinkedStack DigitStack;
//	StackInit(&DigitStack);
//	int Result = 0;
//	char Node = 0;
//
//	for (int i = 0;i < len;++i)
//	{
//		if (IsDigit(pPostFix[i]))
//		{
//			Push(&DigitStack, pPostFix[i]);
//
//		}
//		else
//		{
//			int Op2 = Pop(&DigitStack)-'0';
//			int Op1 = Pop(&DigitStack)-'0';
//
//			switch (pPostFix[i])
//			{
//				case'+':
//					Result = Op1 + Op2;
//					Node = Result + '0';
//					Push(&DigitStack, Node);
//					break;
//				case'-':
//					Result = Op1 - Op2;
//					Node = Result + '0';
//					Push(&DigitStack, Node);
//					break;
//				case'*':
//					Result = Op1 * Op2;
//					Node = Result + '0';
//					Push(&DigitStack, Node);
//					break;
//				case'/':
//					Result = Op1 / Op2;
//					Node = Result + '0';
//					Push(&DigitStack, Node);
//					break;
//			}
//		}
//	}
//
//	
//	int Ultimate_Result = Pop(&DigitStack) - '0';
//
//
//	return Result;
//}
//
//bool IsDigit(char input)
//{
//	if (48 <= input && input <= 57)
//	{
//		return true;
//	}
//	else
//		return false;
//
//}
