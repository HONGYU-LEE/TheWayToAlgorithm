int rob(int* nums, int numsSize){
    int prenum = 0, count = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int temp = count;
        count = prenum + nums[i] < count ? count : prenum + nums[i];
        prenum = temp; 
    }

    return count;
}

