class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1) return s;
        map<int,int>mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        char odd;
        if(s.size() % 2 == 1)
        {
            for(auto &x : mp)
            {
                if(x.second%2 == 1)
                {
                    odd = x.first;
                }
            }
        }
        string ans = "";
        int currSize = 0;
        for(auto &x : mp)
        {
            ans += string(x.second/2, x.first);
        }
        string temp = ans;
        if(s.size() % 2 == 1)
        {
                    ans += odd;
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};