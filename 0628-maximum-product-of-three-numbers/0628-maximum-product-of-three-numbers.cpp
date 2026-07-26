class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int best_pos = nums[n-1] * nums[n-2] * nums[n-3];
        int best_neg = nums[n-1] * nums[0] * nums[1];
        return max(best_neg, best_pos);
    }
};