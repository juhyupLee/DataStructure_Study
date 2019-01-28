#include "ArrayStack.h"

void StackInit(ArrayStack * pStack)
{
	pStack->numOfData = 0;
	for (int i = 0; i < MAXINDEX; ++i)
	{
		pStack->StackArray[i] = 0;
	}
	pStack->StackPointer = -1;

}

void Push(ArrayStack * pStack, Data data)
{
	pStack->StackPointer++;
	pStack->StackArray[pStack->StackPointer] = data;
	pStack->numOfData++;

}

Data Pop(ArrayStack * pStack)
{
	Data rtnData = pStack->StackArray[pStack->StackPointer];
	
	for (int i = pStack->StackPointer; i < MAXINDEX- 1; ++i)
	{
		pStack->StackArray[i] = pStack->StackArray[i + 1];
	}
	pStack->numOfData--;
	pStack->StackPointer--;

	return rtnData;
}

Data Peep(ArrayStack * pStack)
{	
	return pStack->StackArray[pStack->StackPointer];
}
