class Solution {
public:
    vector<int> validSequence(string s, string t) {
        vector<int>last(s.size(),0);
        int i = s.size() - 1;
        int j = t.size() - 1;
        while(i >= 0)
        {
            int add = 0;
            if(j >= 0 && s[i] == t[j])
            {
                add = 1;
                j--;
            }
            last[i] = ((i + 1 < s.size()) ? last[i+1] : 0) + add;
            i--;
        }
        vector<int>ans;
        i = 0;
        j = 0;
        int taken = 0;
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
            {
                ans.push_back(i);
                i++;
                j++;
            }
            else
            {
                if(i + 1 < s.size() && last[i + 1] >= (t.size() - j - 1) && !taken)
                {
                    ans.push_back(i);
                    taken = 1;
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        return (j == t.size()) ? ans : vector<int>();
    }
};