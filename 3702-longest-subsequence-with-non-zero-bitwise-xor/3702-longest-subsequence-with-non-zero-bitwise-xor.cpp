class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xors = 0;
        int valid = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                valid = 1;
            }   
            xors = xors ^ nums[i];
        }
        if(!valid)
        {
            return 0;
        }
        if(xors == 0)
        {
            return nums.size() - 1;
        }
        return nums.size();
    }
};