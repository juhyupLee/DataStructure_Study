#include "CLinkedList Apply Stack.h"

void StackInit(CList * plist)
{
	ListInit(plist);

}

void Push(CList * plist, Data data)
{
	plist->before = plist->tail;
	LInsert(plist, data);

}

Data Pop(CList * plist)
{
	
	plist->cur = plist->tail;
	//plist->before  = 
	return LRemove(plist);

}

int IsEmpty(CList * plist)
{
	if (nullptr == plist->tail)
		return FALSE;
	else
		return TRUE;
}

Data Peek(CList * plist)
{
	if (nullptr == plist->tail)
	{
		return -1;
	}
	else
	{
		return plist->tail->data;
	}
}
