class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        int idx = nums.size();
        mp[val] = idx;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = nums[nums.size() - 1];
        int lastIdx = nums.size() - 1;
        int removeIdx = mp[val];
        swap(nums[removeIdx], nums[lastIdx]);
        mp[last] = removeIdx;
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */