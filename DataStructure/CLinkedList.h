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

typedef CList List;

void ListInit2(List* plist);
//void LInsert(List* plist, Data data);
//void LInsertFront(List* plist, Data data);
//
//int CLFirst(List* plist, Data* pData);
//int CLNext(List* plist, Data* pData);
//Data LRemove(List* plist);
//int CLCount(List* plist);
//



