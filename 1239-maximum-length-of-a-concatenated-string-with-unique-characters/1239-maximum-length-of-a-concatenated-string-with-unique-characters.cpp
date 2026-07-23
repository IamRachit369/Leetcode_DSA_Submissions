class Solution {
public:
    unordered_map<string, int>mp;
    int n;
    bool isValid(string s, string t)
    {
        vector<int>arr(26);
        for(int i = 0; i < s.size(); i++)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a'] > 1) return false;
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(arr[t[i]-'a'] > 0) return false;
        }
        return true;
    }
    int recur(vector<string>&nums, string curr, int i)
    {
        if(i == n) return curr.size();
        if(mp.find(curr) != mp.end()) return mp[curr];
        int include = -1;
        if(isValid(nums[i], curr))
        {
            include = recur(nums, curr + nums[i], i + 1);
        }
        int exclude = recur(nums, curr, i + 1);
        return max(include, exclude);
    }
    int maxLength(vector<string>& nums) {
        n = nums.size();
        string curr = "";
        return recur(nums, curr, 0);
    }
};