class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //if smallest is odd, then true
        int parity = 0;
        for(int i = 1; i < nums1.size(); i++)
        {
            if(nums1[i]%2 != nums1[i-1]%2)
            {
                parity = 1;
            }
        }
        int minVal = *min_element(nums1.begin(), nums1.end());
        if(!parity) return true;
        if(minVal%2 == 1) return true;
        return false;
    }
};