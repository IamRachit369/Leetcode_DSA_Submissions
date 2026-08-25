class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = 1;
        }
        for(int i = 1; i <= 200; i++)
        {
            int curr = k * i;
            if(mp.find(curr) == mp.end())
            {
                return curr;
            }
        }
        return -1;
    }
};