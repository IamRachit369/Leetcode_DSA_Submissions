class Solution {
public:
    int dp[21][21];
    int recur(vector<int>&nums, int l, int r)
    {
        if(l == r) return nums[l];
        if(dp[l][r] != -1) return dp[l][r];
        int left = nums[l] - recur(nums, l + 1, r);
        int right = nums[r] - recur(nums, l, r - 1);
        return dp[l][r] = max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return recur(nums, 0, nums.size() - 1) >= 0;
    }
};