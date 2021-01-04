class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    //Ϊ�˱�֤O(1)�Ĳ���ɾ��������ÿ��Ҫɾ�����ݵ�ʱ��ͻὫ���ݺ�β������������Ҳ��β������
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //�Ѿ�����������Ҫ���룬ֱ�ӷ���false
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
        //��ѯ�Ƿ���ڣ���������ɾ��ʧ��
        if (numToIndex.count(val) == 0)
        {
            return false;
        }

        numToIndex[nums.back()] = numToIndex[val];  //��Ԫ����ĩβ��ֵ���н�������������
        swap(nums[numToIndex[val]], nums.back());

        numToIndex.erase(val);  //��������ĩβ��valɾ��
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];  //�������һ��Ԫ��
    }
private:
    vector<int> nums;                   //ʵ�ʴ洢Ԫ�ص�����
    unordered_map<int, int> numToIndex;  //Ԫ�������±��ӳ��
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */