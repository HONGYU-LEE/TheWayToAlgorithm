int strStr(char * haystack, char * needle){
    const char* src = haystack;
    const char* sub = needle;
    int i = 0, j = 0, k = 0;

    if(NULL == *needle)
        return 0;

    while(src[i] && i <= (strlen(sub) - strlen(src)))
    {
        while(src[i] == sub[j] && sub[j])
        {
            i++;
            j++;
        }
        if(sub[j] == '\0')
        {
            return k;
        }
        else
        {
            i = ++k;
            j = 0;
        }
    }
    return -1;
}
