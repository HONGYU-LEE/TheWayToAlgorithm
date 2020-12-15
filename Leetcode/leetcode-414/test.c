int thirdMax(int* nums, int numsSize){
    int i;
    long max = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] > max)
            max = nums[i];
    }
    //找出最大值
    
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != max && nums[i] > second)
            second = nums[i];
    }
    //找出第二大

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != max && nums[i] != second && nums[i] > third)
            third = nums[i];
    }
    //找到第三大

    if(third != LONG_MIN)
        return third;
    else
        return max;
}
