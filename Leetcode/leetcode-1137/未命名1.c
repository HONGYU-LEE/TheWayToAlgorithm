class Solution {
public:
    int tribonacci(int n) {
        int t1=0,t2=1,t3=1,t;
        if(n==0)
            return 0;
        else if(n<=2)
            return 1;
        while(n-->2)
        {
            t = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = t;
        }
        return t;
    }
};
