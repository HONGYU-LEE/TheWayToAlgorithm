char * toLowerCase(char * str){
    char *src = str;
    while(*str)
    {
        if(*str >= 'A' && *str <= 'Z')
            *str += 32;

        *str++;
    }

    return src;
}
