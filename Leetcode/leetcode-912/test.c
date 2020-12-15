void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int PrevCurMethod(int* arr, int begin, int end)
{
	int cur = begin, prev = begin - 1;
	int pivot = arr[end];
	while (cur < end)
	{
		if (arr[cur] < pivot && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[cur], &arr[prev]);

	return prev;
}

void QuickSort(int *arr, int begin, int end)
{
	if (begin < end)
	{
		int pivot = PrevCurMethod(arr, begin, end);

		QuickSort(arr, begin, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize){

    *returnSize = numsSize;
    QuickSort(nums, 0, numsSize - 1);

    return nums;
}
