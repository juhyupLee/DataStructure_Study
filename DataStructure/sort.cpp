#include "sort.h"

void InsertSorting(int * arr, int n)
{

	int i = 0;
	int j = 0;
	int SaveIndex = 0;
	int InsertValue = 0;


	for (i = 0;i < n - 1;++i)
	{
		InsertValue = arr[i + 1];
		SaveIndex = i + 1;
		for (j = i;j >= 0;--j)
		{
			
			if (InsertValue < arr[j])
			{
				SaveIndex = j;
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
			
		}
		arr[SaveIndex] = InsertValue;

	}
}
