bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 0, end = n;

        while(begin + 1 < end)
        {
            int mid = begin + (end - begin) / 2;
            if(isBadVersion(mid))
            {
                end = mid;
            }
            else
            {                
                begin = mid;
            }
        }

        if(isBadVersion(begin))
            return begin;

        return end;
    }
};
