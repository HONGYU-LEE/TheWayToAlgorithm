bool isPalindrome(char * s){
    int slen = strlen(s);
    char* str = s;
    int strlens = 0, begin = 0, end, i;
    for(i = 0; i < slen; i++)
    {
        if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            str[strlens++] = s[i];
        }
    }
    for(i = 0; i < strlens; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    end = strlens - 1;
    while(begin < end)
    {
        if(str[begin] == str[end])
        {
            begin++;
            end--;
        }
        else
            return false;
    }

    return true;
}
