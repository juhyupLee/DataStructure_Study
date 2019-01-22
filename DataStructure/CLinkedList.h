#pragma once
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _CLL
{

	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;

}CList;


void ListInit(CList* plist);
void LInsert(CList* plist, Data data);
void LInsertFront(CList* plist, Data data);

int LFirst(CList* plist, Data* pData);
int LNext(CList* plist, Data* pData);
Data LRemove(CList* plist);
int LCount(CList* plist);




