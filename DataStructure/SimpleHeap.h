#pragma once
#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100
typedef int HData;
typedef int Priority;


typedef struct _heapElem
{
	Priority pr;
	HData data;

}HeapElem;

typedef struct _heap
{
	int NumOfData;
	HeapElem HeapArr[HEAP_LEN];

}Heap;

int FindParent(int num);
int FindLeftNode(int num);
int FindRightNode(int num);
void HeapInit(Heap* ph);
bool HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);

HData HDelete(Heap* ph);

