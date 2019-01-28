#pragma once

typedef int Data;
#define MAXINDEX 1000

typedef struct _ArrayStack
{
	Data StackArray[MAXINDEX];
	int StackPointer;
	int numOfData;

}ArrayStack;

void StackInit(ArrayStack* pStack);
void Push(ArrayStack* pStack, Data data);
Data Pop(ArrayStack* pStac);
Data Peep(ArrayStack* pStack);

