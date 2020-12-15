int pivotIndex(int* nums, int numsSize){
    int sum = 0, leftnum = 0, i;
    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    for(i = 0; i < numsSize; i++)
    {
        if(leftnum == (sum - leftnum - nums[i]))
            return i;
        else
            leftnum += nums[i];
    }

    return -1;
}
