class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        if(x == y)
        {
            return;
        }
        int parX = find(x);
        int parY = find(y);
        if(parX == parY)
        {
            return;
        }
        if(parX < parY)
        {
            parent[parY] = parX;
        }
        else
        {
            parent[parX]  = parY;
        }
    }
    string smallestEquivalentString(string s, string t, string baseStr) {
       parent.resize(26,0);
       rank.resize(26,0);
       for(int i = 0; i < 26; i++)
       {
        parent[i] = i;
       }
       for(int i = 0; i < s.size(); i++)
       {
            if(find(s[i] - 'a') == find(t[i] - 'a'))
            {
                continue;
            }
            else
            {
                Union(s[i] - 'a', t[i] - 'a');
            }
       } 
       string ans = "";
       for(int i = 0; i < baseStr.size(); i++)
       {
        ans += (char)((char)find(baseStr[i] - 'a') + 'a');
       }

       return ans;
    }
};