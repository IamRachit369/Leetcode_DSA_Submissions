class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long curr = accumulate(nums.begin(), nums.begin() + n/2, 0LL);
        for(int i = 0; i < n; i++)
        {
            curr -= nums[i];
            curr += nums[(i + n/2)%n];
            if(2 * curr > total)
            {
                ans++;
            }
        }
        return ans;
    }
};