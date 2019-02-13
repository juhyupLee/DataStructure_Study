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
	// ���� ����������� d1�� �켱������ ��ū���̰�,
	// ������������ d2�� �켱������ ��ū���̰�
	// ������ 0�̴�

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

	if (ph->Comp(LeftChildData, RightChildData) > 0) // LeftChildData�� �켱������ ��ũ�ٸ�
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
	HData LastNode = ph->HeapArr[ph->numOfData]; //��������� ��Ƴ���
	ph->HeapArr[1] = LastNode; // Root(1) ��忡�ٰ� ��������� ����


	while (true)
	{
		int ChildIndex = UsefulHeap::Suitable_ChildNode(ph, ParentIndex);

		if (ChildIndex > LastIndex)
			break;

		HData ChildData = ph->HeapArr[ChildIndex];
		HData ParentData = ph->HeapArr[ParentData];

		if (ph->Comp(ChildData, ParentData) > 0)// ChildData�� �켱������ ��ũ��
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
