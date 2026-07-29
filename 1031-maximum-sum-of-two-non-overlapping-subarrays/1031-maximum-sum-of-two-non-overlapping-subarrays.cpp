class Solution {
public:
    int n;
    bool isValid(int x)
    {
        return x>= 0 && x < n;
    }
    bool isDifferent(int i, int j, int x, int y)
    {
        return i > y || j < x;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int>prefix(nums.size());
        n = nums.size();
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int idx = i + firstLen - 1;
            if(!isValid(idx))
            {
                break;
            }
            int currSum = prefix[idx] - ((i - 1) >= 0 ? prefix[i-1] : 0 );
            for(int j = 0; j < n; j++)
            {
                int idy = j + secondLen - 1;
                if(!isValid(idy))
                {
                    break;
                }
                int secondSum = prefix[idy] - ((j - 1) >= 0 ? prefix[j-1] : 0 );
                if(isDifferent(i, idx, j, idy))
                {
                    ans = max(ans, currSum + secondSum);
                }
            }
        }
        return ans;
    }
};