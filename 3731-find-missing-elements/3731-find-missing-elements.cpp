class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int min = nums[0];
        int max = nums[nums.size() - 1];
        int curr = 0;
        for(int i = min; i<= max; i++)
        {
            if(i != nums[curr])
            {
                ans.push_back(i);
            }
            else
            {
                curr++;
            }
        }
        return ans;
    }
};