class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&nums, int i, vector<int>&st)
    {
        if(i == nums.size())
        {
            ans.push_back(st);
            return;
        }
        st.push_back(nums[i]);
        recur(nums, i + 1, st);
        st.pop_back();
        recur(nums, i + 1, st);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>st;
        recur(nums, 0, st);
        return ans;
    }
};