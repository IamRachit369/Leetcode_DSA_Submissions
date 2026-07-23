class Solution {
public:
    int dfs(vector<int>&edges, vector<int>&count, int curr, int idx, vector<int>&visited)
    {
        visited[idx] = 1;
        if(edges[idx] == -1) return -1;
        if(visited[edges[idx]] && count[edges[idx]] == 0)
        {
            return -1;
        }
        if(count[edges[idx]] != 0)
        {
            return curr - count[edges[idx]] + 1;
        }
        count[idx] = curr;
        int ans = dfs(edges, count, curr + 1, edges[idx], visited);
        count[idx] = 0;
        return ans;
    }
    int longestCycle(vector<int>& edges) {
        //do a dfs, in the dfs keep a new state count and also keep a vector 
        int n = edges.size();
        vector<int>visited(n,0);
        int ans = -1;
        vector<int>count(n,0);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                ans = max(ans, dfs(edges, count, 1, i, visited));
            }
        }
        return ans;
    }
};