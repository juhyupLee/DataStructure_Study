#include "UsefulHeap.h"


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


int UsefulHeap::Comp(HData d1, HData d2)
{
	return (d2 - d1);
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
	HData LeftChildData = ph->HeapArr[FindLefIndex(parentnode)];
	HData RightChildData = ph->HeapArr[FindRightIndex(parentnode)];

	if (ph->Comp(LeftChildData, RightChildData) >0) // LeftChildData가 우선순위가 더크다면
	{

		return FindLefIndex(parentnode);
	}
	else
	{
		return FindRightIndex(parentnode);
	}
}

void UsefulHeap::HInsert(Heap * ph, HData data)
{
	ph->numOfData++;

	int ParentIndex = FindParentIndex(ph->numOfData);
	int ChildIndex = ph->numOfData;
	HData InsertValue = data;

	while (ParentIndex >= 1)
	{
		if (ph->Comp(InsertValue, ph->HeapArr[ParentIndex]) >0)
		{
			ph->HeapArr[ChildIndex] = ph->HeapArr[ParentIndex];
			ChildIndex = ParentIndex;
		}
		else
		{
			break;
		}

		ParentIndex = FindParentIndex(ChildIndex);

	}

	ph->HeapArr[ChildIndex] = InsertValue;

}

UsefulHeap::HData UsefulHeap::HDelete(Heap * ph)
{
	HData RtnData = ph->HeapArr[1];
	
	int ParentIndex = 1;
	int ChildIndex = 0;
	int LastIndex = ph->numOfData;
	

	while (true)
	{
		ChildIndex = UsefulHeap::Suitable_ChildNode(ph, ParentIndex);

		if (ChildIndex >= LastIndex) // 자식이없는상황.
		{
			break;
		}
			

		HData ChildData = ph->HeapArr[ChildIndex];
		HData ParentData = ph->HeapArr[LastIndex];

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

	ph->HeapArr[ParentIndex] = ph->HeapArr[ph->numOfData];
	ph->numOfData--;


	return RtnData;
}
