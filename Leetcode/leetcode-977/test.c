int* sortedSquares(int* A, int ASize, int* returnSize){

    int *array = (int*)malloc(ASize * sizeof(int));
    int Positive = 0;
    int negative = ASize - 1;
    int i = 0;

    while(Positive < ASize && A[Positive] < 0)
        Positive++;
    
    negative = Positive - 1;

    while(Positive <= ASize - 1 && negative >= 0)
    {
        if(A[Positive] * A[Positive] < A[negative] * A[negative])
            array[i++] = A[Positive] * A[Positive++]; 
        else
            array[i++] = A[negative] * A[negative--];
    }

    while(Positive <= ASize - 1)
        array[i++] = A[Positive] * A[Positive++];

    while(negative >= 0)
        array[i++] = A[negative] * A[negative--];


    *returnSize = i;
    return array;
}
