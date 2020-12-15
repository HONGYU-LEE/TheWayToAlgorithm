int myAtoi(char * str){
    int flag = 1, dig;
    char *p = str;
    long ret = 0;
    while(*p == ' ')
        p++;

    if(*p == '-')
    {
        flag = -1;
        p++;
    }
    else if(*p == '+')
    {
        flag = 1;
        p++;
    }

    while(*p >= '0' && *p <= '9')
    {
        dig = *p++ - '0';
        ret = ret * 10 + dig;
        if((int)ret != ret)
            return flag == 1 ? INT_MAX : INT_MIN;
    }
        return flag == 1 ? ret : -ret;
}
