#include "QuickSort.h"
#include <iostream>
using namespace std;

int Partition(int arr[], int left, int right)
{

	int Mid = (left + right) / 2;

	int Pivot = (arr[left] + arr[right] + arr[Mid])/3;
	//int Pivot = arr[left];

	int High = right;
	int Low = left + 1;
	cout << Pivot << " ";

	while (Low <= High)
	{
		while (Pivot >= arr[Low]&& Low<=High)
		{
			Low++;
		}
		while (Pivot <= arr[High]&&High>=left+1)
		{
			High--;
		}

		if (Low < High)
		{
			Swap(arr, High, Low);
		}
	}

	Swap(arr, left, High);

	return High;
}

void QuickSort(int arr[], int left, int right)
{
	
	if (left < right)
	{
		int Pivot = Partition(arr, left, right);
		QuickSort(arr, left, Pivot - 1);
		QuickSort(arr, Pivot + 1, right);

	}
}

void Swap(int arr[], int leftIdx, int rightIdx)
{
	int temp = arr[leftIdx];
	arr[leftIdx] = arr[rightIdx];
	arr[rightIdx] = temp;

}
