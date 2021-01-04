class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    //为了保证O(1)的插入删除，所以每当要删除数据的时候就会将数据和尾部交换，插入也在尾部进行
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //已经包含了则不需要插入，直接返回false
        if (numToIndex.count(val))
        {
            return false;
        }

        numToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //查询是否存在，不存在则删除失败
        if (numToIndex.count(val) == 0)
        {
            return false;
        }

        numToIndex[nums.back()] = numToIndex[val];  //将元素与末尾的值进行交换，更新索引
        swap(nums[numToIndex[val]], nums.back());

        numToIndex.erase(val);  //将交换到末尾的val删除
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];  //随机返回一个元素
    }
private:
    vector<int> nums;                   //实际存储元素的数组
    unordered_map<int, int> numToIndex;  //元素与其下标的映射
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */