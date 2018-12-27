#include "pch.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node* Head = nullptr;
Node* Tail= nullptr;
Node* Current= nullptr;

bool list_Init()
{
	if (Head != nullptr || Tail != nullptr)
	{
		return false;

	}
	return true;
}

void list_Push(Data data)
{
	Node* pNode = new Node;// Node생성
	pNode->data = data;// 데이터 집어넣기

	if (Head == nullptr)//Node가 아무것도없으면
	{
		Head = pNode;
	}
	else
	{
		Tail->pNext = pNode;	
	}
	Tail = pNode;
	Tail->pNext = nullptr;


}


bool list_Delete(void)
{
	if (Head == nullptr)
	{
		cout << "Nothing in this Container" << endl;

		return false;

	}
	
	Node* pTempNext1 = Head;
	Node* pTempNext2 = Head->pNext;
	cout << pTempNext1->data << endl;
	delete pTempNext1;


	while (pTempNext2 !=nullptr)
	{
		pTempNext1 = pTempNext2;
		pTempNext2 = pTempNext2->pNext;
		cout << pTempNext1->data << endl;
		delete pTempNext1;
	}

	return true;
}

bool list_Seek(Node * pNode, Data data)
{
	return false;
}
