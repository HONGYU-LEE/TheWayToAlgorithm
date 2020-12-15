bool isLongPressedName(char * name, char * typed){
    char* str1 = name;
    char* str2 = typed;

    while(*str1 && *str2)
    {
        if(*str1 == *str2)
        {
            *str1++;
            *str2++;
        }
        else
        {
            *str2++;
        }
    }

    if(*str1 == '\0')
        return true;
    else
        return false;
}
