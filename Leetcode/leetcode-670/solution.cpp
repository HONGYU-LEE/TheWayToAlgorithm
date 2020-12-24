class Solution {
public:
    //贪心
    int maximumSwap(int num) {
        string str(to_string(num)); //转成字符串好比较数字
        vector<int> maxArr(str.size(), - 1);
        int maxIndex = maxArr.size() - 1;

        //第一趟扫描，从右向左记录下该节点右边最大节点的下标
        for(int i = maxArr.size() - 1; i >= 0; i--)
        {
            //如果当前数字大于最大值，则更新最大值
            maxIndex = (str[i] > str[maxIndex]) ? i : maxIndex;
            maxArr[i] = maxIndex;
        }

        //第二趟扫描，从左向右来寻找当前节点是否存在更大值，如果存在则进行交换
        for(int i = 0; i < maxArr.size(); i++)
        {
            if(str[i] < str[maxArr[i]])
            {
                swap(str[i], str[maxArr[i]]);
                return stoi(str);
            }
        }
        return num;
    }
};