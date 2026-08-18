class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size())
        {
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size() - k + 1; i++)
        {
            for(int j = 0; j < k; j++)
            {
                mp[nums[i + j]]++;
            }
        }
        int ans = -1;
        for(auto &x: mp)
        {
            if(x.second == 1)
            {
                ans = max(ans, x.first);
            }
        }
        return ans;
    }
};