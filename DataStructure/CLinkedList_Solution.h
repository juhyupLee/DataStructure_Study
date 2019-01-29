#pragma once
#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList_Sol;



void ListInit(CList_Sol * plist);
void LInsert(CList_Sol * plist, Data data);
void LInsertFront(CList_Sol * plist, Data data);

int LFirst(CList_Sol * plist, Data * pdata);
int LNext(CList_Sol * plist, Data * pdata);
Data LRemove(CList_Sol * plist);
int LCount(CList_Sol * plist);

