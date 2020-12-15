bool isPowerOfTwo(int n){
    if(n <= 0)
        return false;
    else
        return  (0 == (n &= (n-1)))?true : false;
}
