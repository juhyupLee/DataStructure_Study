#include "pch.h"
#include "DLinkedList.h"
#include <stdlib.h>
void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = nullptr;
	plist->comp = nullptr;
	plist->numofData = 0;

}

void LInsert(List * plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numofData)++;

}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next = nullptr)
	{
		return false;
	}
	return 0;
}

int LNext(List * plist, LData * pdata)
{
	return 0;
}

LData LRemove(List * plist)
{
	return LData();
}

int LCount(List * plist)
{
	return 0;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
}
