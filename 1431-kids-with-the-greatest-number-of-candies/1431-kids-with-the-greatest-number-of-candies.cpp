class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxVal = *max_element(candies.begin(), candies.end());
        vector<bool>ans(candies.size());
        for(int i = 0; i < candies.size(); i++)
        {
            ans[i] = (candies[i] + extraCandies >= maxVal) ? true : false; 
        }
        return ans;
    }
};