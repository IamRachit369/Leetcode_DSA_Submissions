class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //find max length of continous ones
        int one_count = count(s.begin(), s.end(), '1');
        s = '1' + s + '1';
        vector<int>zeros;
        int length = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                if(length > 0)
                {   
                    zeros.push_back(length);
                }
                length = 0;
            }
            else
            {
                length++;
            }
        }
        // for(auto &x : zeros)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        if(zeros.size() < 2) return one_count;

        int ans = 0;

        for(int i = 0; i < zeros.size() - 1; i++)
        {
            ans = max(ans, one_count + zeros[i] + zeros[i + 1]);
        }
        return ans;
    }
};