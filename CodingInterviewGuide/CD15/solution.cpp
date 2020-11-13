/*
    维护一个双端队列，保证队头始终为窗口中最大的数据，因此我们在插入时把所有比该数据小的数据全部删除，保证最大值为队头
    并且队列中保存的是下标，通过计算当前位置-窗口大小来判断数据是否滑动出去

    1.队列为空时可以直接插入
    2.当插入数据小于队尾时直接插入
    3.当插入数据大于队尾时不停的删除队尾数据，直到队列为空或者队尾比当前数据大
    4.如果队列满了则将队头滑动出去
*/

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void maxSlidingWindow(vector<int>& arr, int windowSize)
{
    deque<int> dq;    //双端队列中存储的是下标，方便进行窗口的计算
    for(int i = 0; i < arr.size(); i++)
    {
        //如果插入的数据大于队尾，则将它移除，
        //因为新插入的数据位于窗口的最右侧，比他小的数值不会影响窗口，可以全部去掉
        while(!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);    //放入当前数据的下标
        
        //如果窗口满了，则将最右侧数据划出
        if(dq.front() == i - windowSize)
        {
            dq.pop_front();
        }
        
        //当窗口塞满后才开始获取最大值
        if(i >= windowSize - 1)
        {
            cout << arr[dq.front()] << " ";
        }
    }
}

int main()
{
    int count = 0, size;

    while(cin >> count >> size)
    {
        vector<int> arr(count);
        for(int i = 0; i < count; i++)
        {
            cin >> arr[i];
        }
        maxSlidingWindow(arr, size);
    }
    
    return 0;
}