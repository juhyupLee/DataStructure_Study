#pragma once
#include "CLinkedList.h"

void StackInit(CList* plist);
void Push(CList* plist, Data data);
Data Pop(CList* plist);
int IsEmpty(CList* plist);
Data Peek(CList* plist);
