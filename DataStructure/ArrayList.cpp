//#include "pch.h"
//#include "ArrayList.h"
//#include "DLinkedList.h"

//void ListInit(List * plist)
//{
//	//Array list Init
//
//	plist->curPosition = 0;
//	plist->numofData = 0;
//
//
//}
//
//void LInsert(List * plist, LData data)
//{
//	plist->arr[plist->curPosition] = data;
//	plist->curPosition++;
//	plist->numofData++;
//
//
//}
//
//int LFirst(List * plist, LData * pdata)
//{
//	if (plist->numofData > 0)
//	{
//		plist->curPosition = 0;
//		*pdata = plist->arr[plist->curPosition];
//		return 1;
//	}
//	else
//	{
//		return 0;
//
//	}
//
//}
//
//int LNext(List * plist, LData * pdata)
//{
//	if (plist->numofData > 0)
//	{
//		plist->curPosition++;
//		if (plist->curPosition >=plist->numofData)
//			return 0;
//
//		*pdata = plist->arr[plist->curPosition];
//		return 1;
//
//	}
//	else
//	{
//		return  0;
//
//	}
//
//}
//
//LData LRemove(List * plist)
//{
//	LData data = plist->arr[plist->curPosition];
//	
//	int Current_Index = plist->curPosition;
//	plist->curPosition--;
//
//   
//		
//	while (Current_Index <= plist->numofData - 1)
//	{
//		plist->arr[Current_Index] = plist->arr[Current_Index+1];
//		Current_Index++;
//	}
//	plist->numofData--;
//
//	
//	
//	return data;
//}
//
//int LCount(List * plist)
//{
//	
//	return plist->numofData;
//
//}