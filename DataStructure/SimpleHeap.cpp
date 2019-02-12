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
	ph->NumOfData++; //Pointer 이자, 갯수인 NumOfData증가

	int CurentIndex = ph->NumOfData;

	HeapElem NewNode; // HeapElem Heap[] 이니깐 객체 그자체를 넘겨줘야함

	NewNode.data = data;
	NewNode.pr = pr;

	ph->HeapArr[CurentIndex] = NewNode;// 일단 제일 마지막에 넣고

	int ParentIndex = FindParent(CurentIndex);
	if (ParentIndex == 0)
		return;

	while (ParentIndex>=1 && ph->HeapArr[ParentIndex].pr > ph->HeapArr[CurentIndex].pr)
	{  
		//부모노드와 스왑
		HeapElem temp = ph->HeapArr[ParentIndex];
		ph->HeapArr[ParentIndex] = ph->HeapArr[CurentIndex];
		ph->HeapArr[CurentIndex] = temp;
		CurentIndex = ParentIndex;
		//스왑된 노드에서 부모노드 탐색
		ParentIndex = FindParent(CurentIndex);
	}

}

HData HDelete(Heap * ph)
{
	// Root노드 반환하고, 
	HData RtnData = ph->HeapArr[1].data;
	//마지막 노드 첫번째로 올리고, 정렬
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

	while (ChildNode <=ph->NumOfData && ph->HeapArr[ChildNode].pr < ph->HeapArr[ParentNode].pr)// 자식노드가 우선순위가 더크면
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
