int removeElement(int* nums, int numsSize, int val){
    int x = 0;
    int y = 0;
    while(x < numsSize)
    {
        if(nums[x] != val)
        {
           nums[y++] = nums[x++]; 
        }
        else
        {
            x++;
        }
    }
    return y;
}
