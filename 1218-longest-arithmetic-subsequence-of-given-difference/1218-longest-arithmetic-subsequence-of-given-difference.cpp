class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = 1 + mp[arr[i] - difference];
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};