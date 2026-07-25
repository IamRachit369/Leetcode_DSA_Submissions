class Solution {
public:
    int n;
    vector<int>start;
    vector<int>dp;
    int recur(vector<pair<pair<int,int>,int>>&jobs, int i)
    {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int next = lower_bound(start.begin(), start.end(), jobs[i].first.second) - start.begin();
        int pick = jobs[i].second + recur(jobs, next);
        int no_pick = recur(jobs, i + 1);
        return dp[i] = max(pick, no_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        n = profit.size();
        dp.resize(n + 1, -1);
        vector<pair<pair<int,int>,int>>jobs;
        for(int i = 0; i < n; i++)
        {
            jobs.push_back({{startTime[i], endTime[i]},profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(int i = 0; i < n; i++)
        {
            start.push_back(jobs[i].first.first);
        }
        return recur(jobs, 0);
    }
};