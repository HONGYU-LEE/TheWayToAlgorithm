int lengthOfLastWord(char * s){
    int length = 0;
    int end = strlen(s);

    if(end == 0)
        return 0;

    int i = end - 1, j;

    while(s[i] == ' ' && i > 0)
        i--;
    for(j = i; j >= 0; j--)
    {
        if(s[j] != ' ')
            length++;
        else 
            break;
    }

    return length;
}

