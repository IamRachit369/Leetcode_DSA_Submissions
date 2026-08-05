class Solution {
public:
    void dfs(int root, unordered_map<int,vector<int>>&adj, vector<int>&visited)
    {
        visited[root] = 2;
        for(auto &x : adj[root])
        {
            if(!visited[x])
            {
                dfs(x,adj,visited);
            }
        }
    }
    bool check(int root, unordered_map<int,vector<int>>&adj, vector<int>&visited)
    {
        if(visited[root] == 2) return false;
        visited[root] = 1;
        for(auto &x : adj[root])
        {
            if(visited[x] != 1)
            {
                if(!check(x,adj,visited))
                {
                    return false;
                }
            }
        }
        return true;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < nums.size(); i++)
        {
            int u = nums[i][0];
            int v = nums[i][1];
            adj[u].push_back(v);
        }
        vector<int>visited(n,0);
        dfs(k, adj, visited);
        int toRemove = accumulate(visited.begin(), visited.end(), 0)/2;
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0)
            {
                if(!check(i, adj, visited))
                {
                    for(int i = 0; i < n; i++)
                    {
                        ans.push_back(i);
                    }
                    return ans;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(visited[i] != 2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }   
};