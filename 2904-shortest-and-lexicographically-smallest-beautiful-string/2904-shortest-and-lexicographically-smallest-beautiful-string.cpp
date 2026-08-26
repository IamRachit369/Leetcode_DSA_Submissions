class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for(int i = k; i <= s.size(); i++)
        {
            string res = "";
            for(int j = 0; j <= s.size() - i; j++)
            {
                string temp = s.substr(j, i);
                int count = 0;
                for(auto &x : temp)
                {
                    count += (x == '1') ? 1 : 0;
                }
                if(count == k)
                {
                    if(res.empty() || temp < res)
                    {
                        res = temp;
                    }
                }
            }
            if(!res.empty()) 
            {
                return res;
            }
        }
        return "";
    }
};