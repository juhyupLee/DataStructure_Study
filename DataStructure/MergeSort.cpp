#include "MergeSort.h"

void Divide(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left == right)
	{
		return;
	}

	Divide(arr, left, mid);
	Divide(arr, mid + 1, right);
	Merge(arr, left, mid, right);

}

void Merge(int arr[], int left, int mid, int right)
{

	int LeftIdx = left;
	int RightIdx = mid + 1;
	int SortLength = (right - left) + 1;
	int* SortArr = new int[SortLength];
	int SortIdx = 0;
	while (true)
	{
		if (LeftIdx > mid)// 왼편섹터는 탐색 끝남
		{
			while (SortIdx < SortLength)
			{
				SortArr[SortIdx++]= arr[RightIdx++];
			}
			break;
		}
		if (RightIdx > right)
		{
		while (SortIdx < SortLength)
			{
				SortArr[SortIdx++] = arr[LeftIdx++];
			}
			break;
		}
		if (arr[LeftIdx] < arr[RightIdx])
		{
			SortArr[SortIdx++] = arr[LeftIdx++];
		}
		else
		{
			SortArr[SortIdx++] = arr[RightIdx++];
		}
	}

	int j = 0;

	for (int i = left ; i <= right;++i)
	{
		arr[i] = SortArr[j++];
	}

	delete[] SortArr;

}
