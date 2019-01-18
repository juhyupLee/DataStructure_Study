#pragma once
#define TRUE 1
#define FALSE 0

typedef int LData;
enum {LeftValue_Bigger=0,RightValue_Bigger};
typedef struct _node
{
	LData data;
	_node* next;

}Node;

typedef struct _LinkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int numofData;
	int(*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;


void ListInit(List* plist);
void LInsert(List* plist, LData data);

void SInsert(List * plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

int Compare(LData d1, LData d2);

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));
