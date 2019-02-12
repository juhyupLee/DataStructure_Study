#include "SimpleHeap.h"

int FindParent(int num)
{
	return num / 2;
}

int FindLeftNode(int num)
{
	return (num) * 2;

}
int FindRightNode(int num )
{

	return ((num) * 2)+1;
}
void HeapInit(Heap * ph)
{
	ph->NumOfData = 0;
	//ph->HeapArr[0]

}

bool HIsEmpty(Heap * ph)
{
	if (ph->NumOfData == 0)
		return true;
	else
		return false;
}

void HInsert(Heap * ph, HData data, Priority pr)
{
	ph->NumOfData++; //Pointer ����, ������ NumOfData����

	int CurentIndex = ph->NumOfData;

	HeapElem NewNode; // HeapElem Heap[] �̴ϱ� ��ü ����ü�� �Ѱ������

	NewNode.data = data;
	NewNode.pr = pr;

	ph->HeapArr[CurentIndex] = NewNode;// �ϴ� ���� �������� �ְ�

	int ParentIndex = FindParent(CurentIndex);
	if (ParentIndex == 0)
		return;

	while (ParentIndex>=1 && ph->HeapArr[ParentIndex].pr > ph->HeapArr[CurentIndex].pr)
	{  
		//�θ���� ����
		HeapElem temp = ph->HeapArr[ParentIndex];
		ph->HeapArr[ParentIndex] = ph->HeapArr[CurentIndex];
		ph->HeapArr[CurentIndex] = temp;
		CurentIndex = ParentIndex;
		//���ҵ� ��忡�� �θ��� Ž��
		ParentIndex = FindParent(CurentIndex);
	}

}

HData HDelete(Heap * ph)
{
	// Root��� ��ȯ�ϰ�, 
	HData RtnData = ph->HeapArr[1].data;
	//������ ��� ù��°�� �ø���, ����
	int ParentNode = 1;
	ph->HeapArr[ParentNode] = ph->HeapArr[ph->NumOfData];
	ph->NumOfData--; 

	int ChildNode = 0;

	if (FindLeftNode(ParentNode) < FindRightNode(ParentNode))
	{
		ChildNode = FindLeftNode(ParentNode);
	}
	else
	{
		ChildNode = FindRightNode(ParentNode);
	}

	while (ChildNode <=ph->NumOfData && ph->HeapArr[ChildNode].pr < ph->HeapArr[ParentNode].pr)// �ڽĳ�尡 �켱������ ��ũ��
	{
		//Swap
		HeapElem temp = ph->HeapArr[ParentNode];
		ph->HeapArr[ParentNode] = ph->HeapArr[ChildNode];
		ph->HeapArr[ChildNode] = temp;
		ParentNode = ChildNode;
		
		if (FindLeftNode(ParentNode) < FindRightNode(ParentNode))
		{
			ChildNode = FindLeftNode(ParentNode);
		}
		else
		{
			ChildNode = FindLeftNode(ParentNode);
		}

	}


	return RtnData;
}
