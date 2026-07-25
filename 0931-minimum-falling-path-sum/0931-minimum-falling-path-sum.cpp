class Solution {
public:
    vector<vector<int>>dp;
    int n;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    vector<pair<int,int>>directions = {{1,-1},{1,0},{1,1}};
    int dfs(int i, int j, vector<vector<int>>&grid)
    {
        if(dp[i][j] != 101) return dp[i][j];
        int count = INT_MAX;
        for(auto &x : directions)
        {
            int x_ = i + x.first;
            int y_ = j + x.second;

            if(isValid(x_,y_))
            {
                count = min(count, dfs(x_, y_, grid));
            }
        }
        return dp[i][j] = (count == INT_MAX ? 0 : count) + grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        dp.resize(n, vector<int>(n, 101));
        int ans = INT_MAX;
        for(int i = 0; i < matrix[0].size(); i++)
        {
            ans = min(ans, dfs(0, i, matrix));
        }
        return ans;
    }
};