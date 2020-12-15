

int peakIndexInMountainArray(int* A, int ASize){
    int i;
    for(i=0; i<ASize; i++)
    {
        if( A[i]>A[i+1] )
            return i;
    }
    return 0;
}


