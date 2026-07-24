class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> xorPair(2048, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                xorPair[nums[i] ^ nums[j]] = 1;
            }
        }
        vector<int> ans(2048, 0);
        for(int i = 0; i < 2048; i++)
        {
            if(!xorPair[i]) continue;
            for(int j = 0; j < n; j++)
            {
                ans[nums[j] ^ i] = 1;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};