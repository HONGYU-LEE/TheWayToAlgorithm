void reverse(int* arr, int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
        start++;
    }
}
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* arr = (int*)malloc((digitsSize + 1) * sizeof(int));
    int next = 0, i = digitsSize - 1, j = 0, temp;
    digits[digitsSize - 1] += 1;
    while(i >= 0)
    {
        temp = digits[i--] + next;
        if(temp > 9)
        {
            temp %= 10;
            next = 1;
        }
        else
        {
            next = 0;
        }
        arr[j++] = temp;
    }
    if(1 == next)
    {
        arr[j++] = 1;
    }
    reverse(arr, 0, j - 1);
    *returnSize = j;
    return arr;
}
