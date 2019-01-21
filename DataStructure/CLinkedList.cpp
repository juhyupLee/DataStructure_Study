#include "pch.h"
#include "CLinkedList.h"


	void ListInit2(List * plist)
	{
		plist->before = nullptr;
		plist->cur = nullptr;
		plist->tail = nullptr;
		plist->numOfData = 0;
	}

	//void LInsert(List * plist, Data data)
	//{

	//	Node* pNewNode = new Node;

	//	if (plist->tail == nullptr)
	//	{
	//		
	//		plist->tail = pNewNode;
	//		pNewNode->next = pNewNode;
	//	}
	//	else
	//	{
	//		pNewNode->next = plist->tail->next;
	//		plist->tail->next = pNewNode;
	//		plist->tail = pNewNode;
	//	}

	//	plist->numOfData++;

	//}

	//void LInsertFront(List * plist, Data data)
	//{
	//	Node* pNewNode = new Node;
	//	if (plist->tail == nullptr)
	//	{

	//		plist->tail = pNewNode;
	//		pNewNode->next = pNewNode;
	//	}
	//	else
	//	{

	//		pNewNode->next = plist->tail->next;
	//		plist->tail->next = pNewNode;
	//	}
	//	plist->numOfData++;

	//}

	//int LFirst(List * plist, Data * pData)
	//{
	//	if (plist->tail == nullptr)
	//		return FALSE;
	//	else
	//	{
	//		plist->cur = plist->tail->next;
	//		plist->before = plist->tail; //LFirst에서 Cur은 Head, before은 Tail
	//		*pData = plist->cur->data;
	//		return TRUE;
	//	}
	//}

	//int LNext(List * plist, Data * pData)
	//{
	//	if (plist->tail == nullptr)
	//	{
	//		return FALSE;
	//	}
	//	else
	//	{
	//		plist->before = plist->cur;
	//		plist->cur = plist->cur->next;
	//		*pData = plist->cur->data;
	//		return TRUE;
	//	}
	//}

	//Data LRemove(List * plist)
	//{
	//	return Data();
	//}

	//int LCount(List * plist)
	//{
	//	return 0;
	//}
