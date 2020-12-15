int getleft(int numsSize, int target, int* nums)
{
    int left = 0, right = numsSize;
    int mid = (left + right) / 2;
    if(numsSize == 0)
        return -1;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            right = mid;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
        
    }
    if (left == numsSize) 
        return -1;
    return nums[left] == target ? left : -1;
}

int getright(int numsSize, int target, int* nums)
{
    int left = 0, right = numsSize;
    int mid = (left + right) / 2;
    if(numsSize == 0)
        return -1;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
        
    }
    if (left == 0) 
        return -1;
    return nums[left - 1] == target ? (left - 1) : -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
            
    ret[0] = getleft(numsSize, target, nums);
    ret[1] = getright(numsSize, target, nums);

    return ret;
}
