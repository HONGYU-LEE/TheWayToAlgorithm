int removeDuplicates(int* nums, int numsSize){
    int i = 1, j = 1;
    if(numsSize < 2)
        return numsSize;
    while(i < numsSize)
    {
        if(nums[i] != nums[i - 1])
        {
            nums[j++] = nums[i++]; 
        }
        else
        {
            i++;
        }
    }    
    return j;
}
