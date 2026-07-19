class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>mp(26, false);
        int n = s.size();
        stack<char>st;
        unordered_map<char,int>last;
        for(int i = 0; i < n; i++)
        {
            last[s[i]] = i;
        }
        // string curr = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(!mp[s[i]-'a'])
            {
                while(!st.empty() && (st.top() > s[i]) && last[st.top()] > i)
                {
                    // curr.erase(curr.size() - 1, 1);
                    mp[st.top()-'a'] = false;
                    st.pop();
                }
                // curr += s[i];
                st.push(s[i]);
                mp[s[i]- 'a'] = true;
            }
            // cout << curr << endl;
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};