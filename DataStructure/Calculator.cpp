#include "Calculator.h"
#include "LinkedStack.h"




//(1+2*3)/4
int OP_Priority(char input)
{
	switch (input)
	{
	case '+':
	case '-':
		return 3;

	case '*':
	case '/':
		return 5;

	case '(':
		return 1;
	default:
		return -1;
	}



}
int Who_Is_Priority(char input1, char input2)
{
	int Priority_Before = OP_Priority(input1);
	int Priority_After = OP_Priority(input2);

	if (Priority_Before >= Priority_After)
		return 1;
	else if (Priority_Before < Priority_After)
		return 0;
}
char * Infix_To_PostFix(const char * input)
{
	int len = strlen(input);
	//Operator 을 담기위한 스택생성

	LinkedStack OperStack;
	StackInit(&OperStack);

	char* PostFix = new char[len];
	//strcpy_s(PostFix,len, input);
	int PostIndex = 0;

	for (int i = 0; i < len; ++i)
	{
		if (IsDigit(input[i]))
		{
			PostFix[PostIndex++] = input[i];
		}
		else//숫자가아닌 Operator일때... 
		{
			switch (input[i])
			{
				case '(':
					Push(&OperStack, input[i]);
					break;
				case '+':
				case '-':
				case '*':
				case '/':
					if (!IsEmpty(&OperStack) && Who_Is_Priority(Peep(&OperStack), input[i]))
					{
						while (!IsEmpty(&OperStack))
						{
							if ('(' == Pop(&OperStack))
								break;

							PostFix[PostIndex++] = Pop(&OperStack);
						}
					}
					Push(&OperStack, input[i]);
					break;

				case ')':
					while (!IsEmpty(&OperStack))
					{
						char Popchr = Pop(&OperStack);
						if (Popchr == '(')
							break;
						PostFix[PostIndex++] = Popchr;
					}
					break;

			}
		}
	}

	return nullptr;
}


int PostFix_To_Result(char * input)
{
	return 0;
}

bool IsDigit(char input)
{
	if (48 <= input && input <= 57)
	{
		return true;
	}
	else
		return false;

}
