char * reverseOnlyLetters(char * S){
    int low = 0, high = strlen(S) - 1;
    char temp;
    
    while(low < high)
    {
        while(low < high && !isalpha(S[low]))
            low++;
        while(low < high && !isalpha(S[high]))
            high--;

        if(low < high)
        {
            temp = S[low];
            S[low] = S[high];
            S[high] = temp;

            low++;
            high--;
        }
    }

    return S;
}
