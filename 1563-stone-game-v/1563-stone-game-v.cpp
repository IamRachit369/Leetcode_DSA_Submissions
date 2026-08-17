class Solution {
public:
    int dp[501][501];
    vector<int>prefix;
    int recur(int l, int r, vector<int>&nums)
    {   
        int maxVal = INT_MIN;
        if(l >= r) return 0;
        if(dp[l][r] != -1)
        {
            return dp[l][r];
        }
        for(int i = l; i < r; i++)
        {
            int leftSum = prefix[i] - ((l > 0) ? prefix[l - 1] : 0);
            int rightSum = prefix[r] - ((i >= 0) ? prefix[i] : 0);
            if(leftSum > rightSum)
            {
                int toAdd = rightSum + recur(i + 1, r, nums);
                maxVal = max(toAdd, maxVal);
            }
            else if(rightSum > leftSum)
            {
                int toAdd = leftSum + recur(l, i, nums);
                maxVal = max(toAdd, maxVal);
            }
            else
            {
                int leftAdd = leftSum + recur(l, i, nums);
                int rightAdd = rightSum + recur(i + 1, r, nums);
                maxVal = max(maxVal, max(leftAdd, rightAdd));
            }
        }
        return dp[l][r] = maxVal;
    }
    int stoneGameV(vector<int>& nums) {
        prefix.resize(nums.size(),0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        memset(dp, -1, sizeof(dp));
        return recur(0, nums.size() - 1, nums);
    }
};