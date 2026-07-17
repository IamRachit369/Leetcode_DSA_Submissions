class Solution {
public:
    vector<int>visited;
    bool dfs(unordered_map<int,vector<int>>&adj,vector<int>&pos, int root, int curr)
    {
        visited[root] = 1;  
        pos[root] = curr;
        int next = 1 - curr;
        bool ans = true;
        for(auto &x : adj[root])
        {
            if(!visited[x])
            {
                if(!dfs(adj,pos, x, next))
                {
                    return false;
                }
            }
            else
            {
                if(pos[x] == curr) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
         for(int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        visited.resize(n + 1,0);
        vector<int>pos(n + 1,-1);
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(!dfs(adj, pos, i, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};