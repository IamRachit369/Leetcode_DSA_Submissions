class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGCD(nums.size(), 0);
        int curr = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            curr = max(curr, nums[i]);
            prefixGCD[i] = __gcd(nums[i], curr);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        long long ans = 0;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            ans += __gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }
        return ans;
    }
};