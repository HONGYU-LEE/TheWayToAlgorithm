int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *arr = (int*)malloc(ASize * sizeof(int));
    int i, end, start;
    start = 0;
    end = ASize - 1;
    for(i = 0; i < ASize; i++)
    {
        if(A[i] % 2 == 0)
        {
            arr[start++] = A[i];
        }
        else
        {
            arr[end--] = A[i];
        }
    }

    *returnSize = ASize;
    return arr;
}
