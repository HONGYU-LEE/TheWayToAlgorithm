int getcount(int num, int numsSize)
{
    int count = 0;
    for(int i = 0; i <numsSize; i++)
    {
        if(num & 1 == 1)
            count++;
        num >>= 1;    
    }
    return count;
}
 
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int count = 0, num;
    int newsize = (int)pow(2, numsSize);  
    int **arr = (int**)malloc(sizeof(int*) * newsize);
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * newsize);
    *returnSize = newsize;

    for(int i = 0; i < newsize; i++)
    {
        returnColumnSizes[0][i] = getcount(i, numsSize);
        arr[i] = (int*)malloc(sizeof(int) * returnColumnSizes[0][i]);
        num = i;
        count = 0;
        for(int j = 0; j < numsSize; j++)
        {
            if(num & 1 == 1)
                arr[i][count++] = nums[j];
            num >>= 1;
        }
    }

    return arr;
}
