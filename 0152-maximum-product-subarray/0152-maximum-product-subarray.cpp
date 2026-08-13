class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pref = 1;
        int n = nums.size();
        int suff = 1;
        int maxPref = INT_MIN;
        int maxSuff = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            pref = pref * nums[i];
            suff = suff * nums[n - 1 - i];
            maxPref = max(pref, maxPref);
            maxSuff = max(suff, maxSuff);
            if(pref == 0)
            {
                pref = 1;
            }
            if(suff == 0)
            {
                suff = 1;
            }
            ans = max(ans, max(maxPref, maxSuff));
        }
        return ans;
    }
};