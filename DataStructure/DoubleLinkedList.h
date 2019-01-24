#pragma once
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;

}Node;

typedef struct _DlinkedList
{
	Node* head;
	Node* cur;
	int numOfData;

}DBLinkedList;

typedef DBLinkedList DBList;

void ListInit(DBList* plist);
void LInsert(DBList* plist, Data data);

int LFirst(DBList* plist, Data* pdata);
int LNext(DBList* plist, Data* pdata);
int LPrevious(DBList* plist, Data* pdata);
int LCount(DBList* plist);

