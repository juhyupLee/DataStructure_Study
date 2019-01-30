#pragma once

typedef char Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;

}Node;
typedef struct _LinkedStack
{
	Node* StackPointer;
	Node* head;
	int numOfData;

}LinkedStack;

void StackInit(LinkedStack* pStack);
void Push(LinkedStack* pStack, Data data);
Data Pop(LinkedStack* pStack);
Data Peep(LinkedStack* pStack);

int IsEmpty(LinkedStack * pStack);
