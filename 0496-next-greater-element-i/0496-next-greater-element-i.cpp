class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // basically find NGE of nums2
        stack<int> st;
        vector<int> NGE(nums2.size(), -1);

        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                NGE[i] = st.top();
            }

            st.push(nums2[i]);
        }

        unordered_map<int, int> mp;

        for(int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = NGE[i];
        }

        vector<int> ans;

        for(int x : nums1)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};