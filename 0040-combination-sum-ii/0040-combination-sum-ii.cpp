class Solution {
public:
    void recur(int start, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;

            curr.push_back(nums[i]);
            recur(i + 1, nums, target - nums[i], curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        recur(0, candidates, target, curr, ans);

        return ans;
    }
};