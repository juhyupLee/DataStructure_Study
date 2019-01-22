#include "pch.h"
#include "CLinkedList.h"


	void ListInit(CList * plist)
	{
		plist->before = nullptr;
		plist->cur = nullptr;
		plist->tail = nullptr;
		plist->numOfData = 0;
	}

	void LInsert(CList * plist, Data data)
	{

		Node* pNewNode = new Node;
		pNewNode->data = data;

		if (plist->tail == nullptr)
		{
			
			plist->tail = pNewNode;
			pNewNode->next = pNewNode;
		}
		else
		{
			pNewNode->next = plist->tail->next;
			plist->tail->next = pNewNode;
			plist->tail = pNewNode;
		}

		plist->numOfData++;

	}

	void LInsertFront(CList * plist, Data data)
	{
		Node* pNewNode = new Node;
		pNewNode->data = data;

		if (plist->tail == nullptr)
		{

			plist->tail = pNewNode;
			pNewNode->next = pNewNode;
		}
		else
		{

			pNewNode->next = plist->tail->next;
			plist->tail->next = pNewNode;
		}
		plist->numOfData++;

	}

	int LFirst(CList * plist, Data * pData)
	{
		if (plist->tail == nullptr)
			return FALSE;
		else
		{
			plist->cur = plist->tail->next;
			plist->before = plist->tail; //LFirst에서 Cur은 Head, before은 Tail
			*pData = plist->cur->data;
			return TRUE;
		}
	}

	int LNext(CList * plist, Data * pData)
	{
		if (plist->tail == nullptr )
		{
			return FALSE;
		}
		if (plist->before != plist->cur&& plist->cur == plist->tail)
		{
			return FALSE;
		}

		else
		{
			plist->before = plist->cur;
			plist->cur = plist->cur->next;
			*pData = plist->cur->data;
			return TRUE;
		}
	}

	Data LRemove(CList * plist)
	{

		Data RtnData = plist->cur->data;
		Node* DelNode = plist->cur;

		if (plist->cur == plist->tail)// 현재가꼬리인경우
		{
			plist->before->next = plist->cur->next;
			plist->cur = plist->before;
			plist->tail = plist->cur;

		}
		else
		{
			plist->before->next = plist->cur->next;
			plist->cur = plist->before;

		}
		delete(DelNode);

		return RtnData;
	}

	int LCount(CList * plist)
	{
		return 0;
	}
