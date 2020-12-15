void Swap(int* i, int* j)
{
	int temp;
	temp = 	*i;
	*i = *j;
	*j = temp;
}

void Qsort(int* arr, int low, int high)
{
	int pivot;		
	while (low < high)
	{
		pivot = Partition(arr, low, high);
		
		Qsort(arr, low, pivot - 1);
		low = pivot + 1;
	}
}



int Partition(int* arr, int low, int high)
{
	int pivotkey, temp, mid;
	
	mid = low + (high - low) / 2; 
	if(arr[low] > arr[high])
		Swap(&arr[low], &arr[high]);
	if(arr[mid] > arr[high])
		Swap(&arr[mid], &arr[high]);
	if(arr[mid] > arr[low])
		Swap(&arr[mid], &arr[low]);
		
	pivotkey = arr[low]; 
	temp = pivotkey;
	

	while (low < high)
	{
		while (low < high && arr[high] >= pivotkey)
		{
			high--;
		}
		arr[low] = arr[high];
		
		while (low <high && arr[low] <= pivotkey)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = temp;
	return low;
}

void QuickSort(int* arr, int length)
{
	Qsort(arr, 0, length);
} 

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize < 2)
        return false;
    QuickSort(nums, numsSize - 1);

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i - 1])
            return true;
    }

    return false;
}
