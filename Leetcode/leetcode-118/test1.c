int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **arr = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes =(int*) malloc(sizeof(int ) * numRows);
    int i, j;
    for(i = 0; i < numRows; i++)
    {
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        arr[i][0] = arr[i][i] = 1;
    }

    for(i = 1; i < numRows; i++)
    {
        for(j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i -1][j - 1];
        }
    }

    *returnSize = numRows;
    return arr;
}
