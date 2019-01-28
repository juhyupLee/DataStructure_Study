#include "LinkedStack.h"

void StackInit(LinkedStack * pStack)
{
	pStack->head = new Node;
	pStack->numOfData = 0;
	pStack->head->next = nullptr;
	pStack->StackPointer = pStack->head->next;
}

void Push(LinkedStack * pStack, Data data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;

	pNewNode->next = pStack->head->next;
	pStack->head->next = pNewNode;

	pStack->StackPointer = pStack->head->next;
}

Data Pop(LinkedStack * pStack)
{
	Data RtnData = pStack->StackPointer->data;
	Node* DelNode = pStack->StackPointer;

	pStack->head->next = pStack->StackPointer->next;
	pStack->StackPointer = pStack->StackPointer->next;
	delete DelNode;

	return RtnData;
}

Data Peep(LinkedStack * pStack)
{
	if (pStack->StackPointer == nullptr)
		return -1;
	return pStack->StackPointer->data;
}
