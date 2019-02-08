#pragma once
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
	Node*	head;
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} LinkedQueue;



void QueueInit(LinkedQueue * plist);
void Enqueue(LinkedQueue * plist, Data data);
Data Dequeue(LinkedQueue * plist);
int QIsEmpty(LinkedQueue * plist);

