#include "LinkedList Queue.h"

void QueueInit(LinkedQueue * plist)
{
	plist->head = nullptr;
	plist->tail = nullptr;

}

void Enqueue(LinkedQueue * plist, Data data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;
	pNewNode->next = nullptr;

	if (plist->head == nullptr)
	{
		plist->head = pNewNode;
		plist->tail = pNewNode;
	}
	else
	{
		plist->tail->next = pNewNode;
		plist->tail = pNewNode;
	}

}

Data Dequeue(LinkedQueue * plist)
{
	if (plist->head == plist->tail)
	{
		Data rtnData = plist->head->data;
		Node* DelNode = plist->head;

		plist->head = plist->head->next;

		delete DelNode;

		plist->head = nullptr;
		plist->tail = nullptr;


		return rtnData;

	}
	else
	{
		Data rtnData = plist->head->data;
		Node* DelNode = plist->head;

		plist->head = plist->head->next;

		delete DelNode;


		return rtnData;

	}
	
}

int QIsEmpty(LinkedQueue * plist)
{
	
	if (plist->head == nullptr)
	{
		return TRUE;

	}
	else
	{
		return FALSE;
	}
}
