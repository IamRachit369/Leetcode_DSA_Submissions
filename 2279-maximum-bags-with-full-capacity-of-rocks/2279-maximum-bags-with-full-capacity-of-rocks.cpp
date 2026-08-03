class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int total) {
        int n = capacity.size();
        vector<int>left(n,0);
        for(int i = 0; i < n; i++)
        {
            left[i] = capacity[i] - rocks[i];
        }
        sort(left.begin(), left.end());
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(total >= left[i])
            {
                count++;
                total-=left[i];
            }
            else
            {
                break;
            }
        }
        return count;
    }
};