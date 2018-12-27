#pragma once
typedef int Data;

typedef struct struct_Node
{
	Data data;
	struct_Node* pNext;

}Node;

bool list_Init();
void list_Push(Data data);
bool list_Delete(void);
bool list_Seek(Node* pNode, Data data);

