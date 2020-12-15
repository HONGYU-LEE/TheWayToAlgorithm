char * addBinary(char * a, char * b){
    int lenA = strlen(a) - 1, lenB = strlen(b) - 1, i = 0, carry = 0, sum = 0;
    int size = lenA > lenB ? lenA : lenB;
    int numA, numB;

    char* str = (char*)malloc((size + 3) * sizeof(char));
    char temp;
    memset(str, '\0', size + 3);
    while(lenA >= 0 || lenB >= 0 || carry != 0)
    {
        numA = lenA >= 0 ? a[lenA--] - '0' : 0;
        numB = lenB >= 0 ? b[lenB--] - '0' : 0;
        sum = numA + numB + carry;
        str[i++] = sum % 2 + '0';
        carry = sum / 2;
    }

    for(int j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return str;
}

