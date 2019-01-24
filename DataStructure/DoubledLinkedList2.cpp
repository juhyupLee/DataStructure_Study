#include "DoubledLinkedList2.h"

void ListInit(DBList2 * plist)
{
	plist->cur = nullptr;

	plist->head = new Node; //���̳��1
	plist->head->prev = nullptr;

	plist->tail = new Node; //���̳��2
	plist->tail->next = nullptr;

	plist->head->next = plist->tail;
	plist->tail->prev = plist->head; // ���̳��1 ,���̳��2 ����

	plist->numOfData = 0;

}

void LInsert(DBList2 * plist, Data data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;

	//�����۾�
	pNewNode->next = plist->head->next;
	plist->head->next->prev = pNewNode;

	pNewNode->prev = plist->head;
	plist->head->next = pNewNode;

	plist->numOfData++;	
}

int LFirst(DBList2 * plist, Data * pdata)
{
	if (plist->head->next ==plist->tail)// ��尡 ���̳�� tail�� ����Ű�� fail
		return 0;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return 1;
}

int LNext(DBList2 * plist, Data * pdata)
{
	if ( plist->cur->next == plist->tail)
	{
		return 0;
	}
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return 1;
}

int LPrevious(DBList2 * plist, Data * pdata)
{
	if (plist->cur->prev == plist->head)
	{
		return 0;
	}
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return 1;
}

Data LRemove(DBList2 * plist)
{
	Node* pDelNode = plist->cur;
	Data RtnData = plist->cur->data;

	Node* pNextNode = plist->cur->next;
	Node* pPrevNode = plist->cur->prev;
	//Dummy Node ������ �׻� ��� ����� Next�� Prev�� ������--> null �� �� ����������

	pPrevNode->next = pNextNode;
	pNextNode->prev = pPrevNode;

	plist->cur = pPrevNode;

	delete pDelNode;

	plist->numOfData--;
	return RtnData;
}

int LCount(DBList2 * plist)
{
	return 0;
}
