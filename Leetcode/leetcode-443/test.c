int compress(char* chars, int charsSize){
    int read = 0, write = 0, anchor = 0, dight;

    for(read = 0; read < charsSize; read++)
    {
        if(read + 1 == charsSize || chars[read] != chars[read + 1])
        {
            chars[write++] = chars[anchor];
            if(read > anchor)
            {
                char s[1000] = {};
                sprintf(s, "%d", read - anchor + 1); 
                for(int i = 0; i < strlen(s); i++)
                {    
                    chars[write++] = s[i];
                }
            }
            anchor = read + 1;          
        }
    }
    return write;
}
