class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2,c;
        
        if( n==1 )
            return 1;
        else if( n==2 )
            return 2;
        while(n-->2)
        {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
