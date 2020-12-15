class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        //先放入k个元素，维护一个有k个元素的堆
        for(size_t i = 0; i < k; i++)
        {
            heap.push(nums[i]);
        }
        //如果比堆顶大则入堆,使堆顶为第K大数据
        for(size_t i = k; i < nums.size(); i++)
        {
            if(heap.top() < nums[i])
            { 
                heap.pop(); 
                heap.push(nums[i]);  
            }           
        }
        return heap.top();
    }
};
