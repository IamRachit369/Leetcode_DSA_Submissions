class Solution {
public:
    vector<vector<int>>ans;
    set<int>st;
    void recur(vector<int>&temp, vector<int>&nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(st.find(nums[i]) == st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                recur(temp, nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        recur(temp, nums);
        return ans;
    }
};