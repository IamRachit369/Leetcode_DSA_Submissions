class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int to_find = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == 1 + nums[i-1])
            {
                to_find += nums[i];
            }
            else
            {
                break;
            }
        }
        while(true)
        {
            if(find(nums.begin(), nums.end(), to_find) != nums.end())
            {
                to_find++;
            }
            else
            {
                return to_find;
            }
        }
        return -1;
    }
};