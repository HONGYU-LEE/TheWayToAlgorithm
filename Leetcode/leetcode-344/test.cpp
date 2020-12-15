class Solution {
public:
    //¼òµ¥µÄreverse
    void reverseString(vector<char>& s) {
        int begin = 0, end = s.size() - 1;

        while(begin < end)
        {
            swap(s[begin++], s[end--]);
        }
    }
};
