
#include "CLinkedList_Solution.h"

void ListInit(CList_Sol * plist)
{
	plist->tail = nullptr;
	plist->cur = nullptr;
	plist->before = nullptr;
	plist->numOfData = 0;
}

void LInsertFront(CList_Sol * plist, Data data)
{
	Node * newNode = new Node;
	newNode->data = data;

	if(plist->tail == nullptr) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

void LInsert(CList_Sol * plist, Data data)
{
	Node * newNode = new Node;
	newNode->data = data;

	if(plist->tail == nullptr) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else 
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(CList_Sol * plist, Data * pdata)
{
	if(plist->tail == nullptr)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(CList_Sol * plist, Data * pdata)
{
	if(plist->tail == nullptr)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(CList_Sol * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // ���� ����� tail�� ����Ų�ٸ�
	{
		if(plist->tail == plist->tail->next)    // �׸��� ������ ���� �����
			plist->tail = nullptr;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete rpos;
	(plist->numOfData)--;
	return rdata;
}

int LCount(CList_Sol * plist)
{
	return plist->numOfData;
}