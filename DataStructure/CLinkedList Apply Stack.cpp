#include "CLinkedList Apply Stack.h"

void StackInit(CList_Sol * plist)
{
	ListInit(plist);

}

void Push(CList_Sol * plist, Data data)
{
	LInsertFront(plist, data);
}

Data Pop(CList_Sol * plist)
{
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	return LRemove(plist);

}

int IsEmpty(CList_Sol * plist)
{
	if (nullptr == plist->tail)
		return FALSE;
	else
		return TRUE;
}

Data Peek(CList_Sol * plist)
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
