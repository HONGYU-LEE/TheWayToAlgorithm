class Solution {
public:
    int fib(int N) {
        int a=0,b=1,c=1;
        if( N==0)
            return 0;
        if( N==1 )
            return 1;
        while(N-->1)
        {
            c = a+b;
            a = b;
            b = c; 
        }
        return c;
    }
};
