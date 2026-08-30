class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int max_elem = max_element(nums.begin(), nums.end()) - nums.begin();
        int min_elem = min_element(nums.begin(), nums.end()) - nums.begin();
        // cout << max_elem << " " << min_elem << endl;
        int first = max(max_elem, min_elem) + 1;
        int second = nums.size() - min(max_elem, min_elem);
        int third = nums.size() - abs(max_elem - min_elem) + 1;
        // cout << first << " " << second << " " << third << endl;
        return min(first, min(second, third));
    }
};