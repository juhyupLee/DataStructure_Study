#pragma once

#define HEAP_LEN 100
typedef char HData;

namespace UsefulHeap
{
	typedef char HData;

	typedef struct _Heap
	{
		int(*Comp)(HData d1, HData d2);
		int numOfData;
		HData HeapArr[HEAP_LEN];

	}Heap;


	void HeapInit(Heap* ph, int(*Func)(HData d1, HData d2));
	int HIsEmpty(Heap* ph);
	void HInsert(Heap* ph, HData data);
	HData HDelete(Heap* ph);
	int Suitable_ChildNode(Heap* ph, int parentnode);
}

