
#include "DoubleLinkedList.h"

void ListInit(DBList * plist)
{
	plist->head = nullptr;
	plist->cur = nullptr;

}

void LInsert(DBList * plist, Data data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;

	pNewNode->next = plist->head;
	pNewNode->prev = nullptr;
	if (nullptr != plist->head)
	{
		plist->head->prev = pNewNode;
	}
	plist->head = pNewNode;
	plist->numOfData++;
}

int LFirst(DBList * plist, Data * pdata)
{
	if (nullptr == plist->head)
	{
		return 0;
	}
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return 1;
}

int LNext(DBList * plist, Data * pdata)
{
	if (nullptr == plist->cur->next)
	{
		return 0;
	}
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return 1;
}

int LPrevious(DBList * plist, Data * pdata)
{
	if (nullptr == plist->cur->prev)
	{
		return 0;
	}
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return 1;


}

int LCount(DBList * plist)
{
	return 0;
}
