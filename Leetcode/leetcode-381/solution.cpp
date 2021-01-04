class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        numToIndexs[val].insert(nums.size());
        nums.push_back(val);

        return numToIndexs[val].size() == 1; //如果里面不止一个则返回false
    }


    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    
    bool remove(int val) {
        //为空则删除失败
        if(numToIndexs.find(val) == numToIndexs.end())
        {
            return false;
        }

        int index = *(numToIndexs[val].begin());    //获取一个重复元素
        numToIndexs[val].erase(index);

        //交换删除元素与末尾元素
        
        swap(nums[index], nums.back());
        numToIndexs[nums[index]].erase(nums.size() - 1);

        //如果删除的是最后一个元素本身，则不需要再去更新下标
        if(index != nums.size() - 1)
        {
            numToIndexs[nums[index]].insert(index);
        }
        
        //如果某一个元素被全部删除，则删除对应的哈希表
        if(numToIndexs[val].empty())
        {
            numToIndexs.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> numToIndexs; //由于和上题不同，此时会出现重复字符，因此需要再嵌套一个哈希表来存储重复值的下标
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */