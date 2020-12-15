int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *t = (int*)malloc(2*sizeof(int));

    for(int i=0; i<numsSize; i++)
        for(int j=i+1; j<numsSize; j++)
                if((nums[i] + nums[j]) == target)
                {
                   t[0] = i;
                    t[1] = j;
                    *returnSize = 2;
                    return t;
                }
    return t;
}
