#pragma once
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;

}Node;

typedef struct _DlinkedList2
{
	Node* head;
	Node* cur;
	Node* tail;
	int numOfData;

}DBLinkedList2;

typedef DBLinkedList2 DBList2;

void ListInit(DBList2* plist);
void LInsert(DBList2* plist, Data data);
int LFirst(DBList2* plist, Data* pdata);
int LNext(DBList2* plist, Data* pdata);
int LPrevious(DBList2* plist, Data* pdata);
Data LRemove(DBList2* plist);
int LCount(DBList2* plist);

