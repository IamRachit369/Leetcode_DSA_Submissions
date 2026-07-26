class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[target - nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i])!=mp.end() && i!= mp[nums[i]])
            {
                return {i,mp[nums[i]]};
            }
        }
        return {-1,-1};
    }
};