#include "pch.h"
#include "DLinkedList.h"
#include <stdlib.h>

namespace DLinkedList
{

	void ListInit(List * plist)
	{
		plist->head = new Node;
		plist->head->next = nullptr;

		plist->cur = nullptr;
		plist->before = nullptr;
		plist->numofData = 0;
		plist->comp = nullptr;
	}

	void SInsert(List* plist, LData data)
	{
		Node* pNewNode = new Node;
		pNewNode->data = data;
		Node* DummyNew = plist->head; // 새로운 움직일 더미를 만들어보자


		while (DummyNew->next != nullptr)// 더미노드넥스트가 null이아닐때 반복문실행
		{
			if (plist->comp(data, DummyNew->next->data) == RightValue_Bigger)
				DummyNew = DummyNew->next;
			else
				break;
		}
		pNewNode->next = DummyNew->next;
		DummyNew->next = pNewNode;
	}

	void LInsert(List * plist, LData data)
	{

		if (plist->comp != nullptr)
		{
			DLinkedList::SInsert(plist, data);
			return;
		}
		Node* NewNode = new Node;
		NewNode->data = data;
		NewNode->next = plist->head->next;
		plist->head->next = NewNode;

		plist->cur = NewNode;
		plist->numofData++;

		//before에대한 추가는 나중에

	}


	int LFirst(List * plist, LData * pdata)
	{
		if (plist->head->next == nullptr)
			return 0;

		plist->cur = plist->head->next;// 
		plist->before = plist->head;// 

		*pdata = plist->cur->data;

		return 1;
	}

	int LNext(List * plist, LData * pdata)
	{
		if (plist->cur->next == nullptr)
			return 0;

		plist->before = plist->cur;
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;

		return 1;
	}

	LData LRemove(List * plist)
	{
		LData RtnData = plist->cur->data;
		Node* pDelNode = plist->cur;

		plist->before->next = plist->cur->next;
		plist->cur = plist->before;// 포인터를 한칸더땡겨야된다

		delete(pDelNode);
		plist->numofData--;

		return RtnData;
	}

	int LCount(List * plist)
	{
		return plist->numofData;
	}

	int Compare(LData d1, LData d2)
	{
		if (d1 < d2)
		{
			return RightValue_Bigger;
		}
		else
			return LeftValue_Bigger;

	}
	void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
	{
		plist->comp = comp;

	}


}

