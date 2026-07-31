class Solution {
public:
    set<vector<int>>ans;
    void recur(int i, vector<int>&nums, int target, vector<int>curr)
    {
        if(target == 0)
        {
            ans.insert(curr);
            return;
        }
        if(i  >= nums.size()) return;
        if(target < 0) return;
        recur(i + 1, nums, target, curr);
        curr.push_back(nums[i]);
        recur(i + 1, nums, target - nums[i], curr);
        recur(i, nums, target - nums[i], curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        recur(0, candidates, target, curr);
        vector<vector<int>>res;
        for(auto &it : ans)
        {
            res.push_back(it);
        }
        return res;
    }
};