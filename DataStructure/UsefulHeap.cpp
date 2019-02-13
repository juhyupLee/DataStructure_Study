#include "UsefulHeap.h"
//#include "SimpleHeap.h"


int FindParentIndex(int num)
{
	return num / 2;
}

int FindLefIndex(int num)
{
	return (num) * 2;

}
int FindRightIndex(int num)
{

	return ((num) * 2) + 1;
}


int Comp(HData d1, HData d2)
{
	return d1 - d2;
	// 만약 양수가나오면 d1이 우선순위가 더큰것이고,
	// 음수가나오면 d2가 우선순위가 더큰것이고
	// 같으면 0이다

}
void UsefulHeap::HeapInit(Heap * ph, int(*Func)(HData d1, HData d2))
{
	ph->Comp = Func;
	ph->numOfData = 0;


}

int UsefulHeap::HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return true;
	else
		return false;
}

int UsefulHeap::Suitable_ChildNode(Heap * ph, int parentnode)
{

	if (ph->numOfData < FindLefIndex(parentnode))
	{

	}

	HData LeftChildData = ph->HeapArr[FindLefIndex(parentnode)];
	HData RightChildData = ph->HeapArr[FindLefIndex(parentnode)];

	if (ph->Comp(LeftChildData, RightChildData) > 0) // LeftChildData가 우선순위가 더크다면
	{

		return LeftChildData;
	}
	else
	{

		return RightChildData;
	}

}

void UsefulHeap::HInsert(Heap * ph, HData data)
{
	
}

HData UsefulHeap::HDelete(Heap * ph)
{
	HData RtnData = ph->HeapArr[1];
	
	int ParentIndex = 1;
	int LastIndex = ph->numOfData;
	HData LastNode = ph->HeapArr[ph->numOfData]; //마지막노드 담아놓기
	ph->HeapArr[1] = LastNode; // Root(1) 노드에다가 마지막노드 덮기


	while (true)
	{
		int ChildIndex = UsefulHeap::Suitable_ChildNode(ph, ParentIndex);

		if (ChildIndex > LastIndex)
			break;

		HData ChildData = ph->HeapArr[ChildIndex];
		HData ParentData = ph->HeapArr[ParentData];

		if (ph->Comp(ChildData, ParentData) > 0)// ChildData가 우선순위가 더크면
		{
			ph->HeapArr[ParentIndex] = ph->HeapArr[ChildIndex];
			ParentIndex = ChildIndex;

		}
		else
		{
			break;
		}
	}


	return RtnData;
}
